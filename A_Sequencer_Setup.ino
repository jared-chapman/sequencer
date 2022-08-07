#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL343.h>
#include <Adafruit_NeoTrellisM4.h>

// Trellis Setup
Adafruit_NeoTrellisM4 trellis = Adafruit_NeoTrellisM4();
Adafruit_ADXL343 accel = Adafruit_ADXL343(12345, &Wire1);

// MIDI setup
#define MIDI_CHANNEL 0

/*
 * Finite State Machine setup
 * 0 - Main screen, 1st row controls, 2nd row voices, bottom 2 rows Sequencer
 * 1 - Note Selection, 1st row controls, 2nd row ?, bottom two rows keyboard
 */
int state    = 0;


// Note Variables
int choosingNoteForPosition = -1;   // When a sequence button is pressed, this represents its position
int tempSelectNote          = -1;   // The note to be placed in sequence position. Temp until it is confirmed
int tempButtonPressed       = -1;   // Used to highlight selected note before it is confirmed
int octave                  = 4;    
int transpose               = 0;


// Sequencer Variables
int sequenceLightInitial    = 16;     // The first pixel being used in the sequencer. Should always be 16
int sequenceLength          = 16;     // Total length of the sequencer
int sequenceLightFinal      = sequenceLightInitial + sequenceLength -1;
int sequencePosition        = 0;      // Initial position of the sequencer
bool playing                = true;


// Clock Variables
int previousClock           = 0;           
int currentMillis           = millis();
int sequencerSpeed          =  500;


// Light Control Variables
// Colors
int off     = trellis.Color(0, 0, 0);
int white   = trellis.Color(255, 255, 255);
int red     = trellis.Color(255, 0, 0);
int orange  = trellis.Color(255, 128, 128);
int yellow  = trellis.Color(255, 255, 0);
int pink    = trellis.Color(255, 0, 255);
int teal    = trellis.Color(0, 255, 255);
int green   = trellis.Color(0, 255, 0);
int blue    = trellis.Color(0, 0, 255);

// Sequencer Colors
int sequencerActiveOff   = teal;    // Active position in sequence, Note off
int sequencerActiveOn    = teal;    // Active position in sequence, Note on
int sequencerInactiveOff = pink;    // Inactive position in sequence, Note off
int sequencerInactiveOn  = white;   // Inactive position in sequence, Note on
int tempSelectColor      = teal;    // Highlight tempSelectedNote

// Main screen colors
int of = off;     // Off
int pp = red;     // Play/Pause
int rs = red;     // Restart
int sd = yellow;  // Slow Down
int su = yellow;  // Speed Up
int cn = green;   // Confirm
int ou = orange;  // Octave Up
int od = orange;  // Octave Down
int oh = off;     // Octave Indicator High
int ol = off;     // Octave Indicator Low
int cc = teal;    // Control Change Active

// Keyboard colors
int bk = red;     // Black Key
int wk = white;   // White Key
int bg = off;     // Background


// The showLights function will always check this array and set lights accordingly  
int lights[]        = {pp, pp, cc, of, od, ou, sd, su,
                       cn, of, of, of, of, of, oh, ol,
                       of, of, of, of, of, of, of, of,    // These two lines will be overridden in sequencerLightControl()
                       of, of, of, of, of, of, of, of};   // This is here to initialize the array


// This array determines if notes are "On" or "Off" in the sequence and will
// Be referenced in the MIDI section (TODO)
int sequenceNotesOnOff[] = {0, 0, 0, 0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0, 0, 0, 0};

// These vaules will be set to MIDI pitch control codes
// -1 will be off
int sequenceNotes[] = {-1, -1, -1, -1, -1, -1, -1, -1,
                       -1, -1, -1, -1, -1, -1, -1, -1};
                       
// Control Codes for accelerometer
int xCCx = 16; // wtf is x?
int xCCy = 17; // y is star power
int xCCz = 18; // z is Jimi playing with his teeth
bool ccActive = true;


                 

void setup() {
    // Set up Trellis
    trellis.begin();
    trellis.setBrightness(50);

    trellis.enableUSBMIDI(true);
    trellis.setUSBMIDIchannel(MIDI_CHANNEL);

    /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL343 ... check your connections */
    Serial.println("Ooops, no ADXL343 detected ... Check your wiring!");
    while(1);
  }
}