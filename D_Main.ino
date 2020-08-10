void sequenceAdvance(){
  /*
   * Increment Sequencer, wrap back to 0. 
   * Note this is only sequence position (1-16), NOT the neopixel to be lit
   * Since typically the sequencer will be on the bottom two rows,
   * 16 will need to be added to this number to get the corresponding
   * Neopixel
   */
  sequencePosition ++;
  if (sequencePosition > sequenceLength-1 or sequencePosition < 0){
    sequencePosition = 0;
  }
}

void sequencerLightControl(){
  /*
   * Controls the lights[] array by changing the correct neopixel to the sequencerActive color,
   * and the rest of the neopixels in the sequencer zone to either the sequencerInactiveOff or  
   * sequencerInactiveOn color, depending on whether the note is on or off.
   * sequenceLightInitial is added to the sequencePosition to give the correct Neopixel position.
   * Note this does not turn lights on or off, only edits the lights[] array used to do so.
   */

  // Show Octave Indicator
  /*
   * Set both octave indicator lights to off
   * Cycle RGB for low if below 4, high if above
   */
  oh = off;
  ol = off;
  switch(octave){
    case 1:
      ol = blue;
      break;
    case 2:
      ol = green;
      break;
    case 3:
      ol = red;
      break;
    case 4:
      break;
    case 5:
      oh = red;
      break;
    case 6:
      oh = green;
      break;
    case 7:
      oh = blue;
      break;
    default:
      break;
  }
  int lowIndicator      = 14;   // For Clarity
  int highIndicator     = 15;
  lights[lowIndicator]  = ol;
  lights[highIndicator] = oh;
  
  if (state == 0){ // Show sequencer
    for(int i = 0; i <sequenceLength; i++){
      if  (i == sequencePosition){ // If active note
        if (sequenceNotesOnOff[i] == 0){
          lights[i+sequenceLightInitial] = sequencerActiveOff;
        } else {
          lights[i+sequenceLightInitial] = sequencerActiveOn;
        }
      } else { // If inactive note
        if (sequenceNotes[i] == -1){
          lights[i+sequenceLightInitial] = sequencerInactiveOff;
        } else {
          lights[i+sequenceLightInitial] = sequencerInactiveOn;
        }
      }
    }
  }
  
  // Show keyboard
  if (state == 1){ 
    for(int i = 0; i < sequenceLength; i++){
      lights[i + sequenceLightInitial] = keyboardLightsDefault[i];
    }
    // If a note is selected but not confirmed, change that button's color
    if (tempButtonPressed > -1){
      lights[tempButtonPressed] = tempSelectColor;
    }
  }
  showLights();
}


void playPause(){
  if (playing){
    playing = false;
    for (int i = 0; i < 88; i++){
      trellis.noteOff(i, 64);
    }
  } else {
    playing = true;
  }
}

void noteSelect(int rootNote, int buttonPressed){
  /*
   * When in state 1 and keyboard is shown, pressing a key button 
   * runs this. It saves the selected key in tempSelectNote 
   * When confirmation key is pressed
   * noteConfirmed is run to finalize and return to state 0
   */
  tempSelectNote = rootNote + (octave * 12) + transpose;
  tempButtonPressed = buttonPressed;

}


void noteConfirmed(){
  /*
   * Sets choosingNoteForPosition to tempSelectNote
   * then resets values to -1
   */
  sequenceNotes[choosingNoteForPosition] = tempSelectNote;
  choosingNoteForPosition = -1;
  tempSelectNote = -1;
  tempButtonPressed = -1;
  state = 0;
}
