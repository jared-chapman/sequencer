# sequencer
A MIDI sequencer designed for the Adafruit Neotrellis M4 board, but also meant to be easily adaptable for other setups

|0  1  2  3  4  5  6  7 |  
|8  9  10 11 12 13 14 15|  
|16 17 18 19 20 21 22 23|  
|24 25 26 27 28 29 30 31|  

State 0:  
0 -     Play/Pause  
1 -     Restart  
2 -     Enable/disable Midi CC changes via accelerometer
4 -     Transpose down 1 half step  
5 -     Transpose up 1 half step  
6 -     Slow down    
7 -     Speed up  
14 -    Octave lower indicator  
15 -    Octave Higher indicator  
16-31 - Select position in sequence, show kayboard (Switch to State 1). Note selected with keyboard will go in this position  

State1:  
0 -     Play/Pause  
1 -     Restart  
2 -     Enable/disable Midi CC changes via accelerometer
4 -     Transpose down 1 half step  
5 -     Slow down  
6 -     Speed up  
7 -     Transpose up 1 octave  
8 -     Confirm selected note  
14 -    Octave lower indicator  
15 -    Octave Higher indicator  
16-31 -   Select Pitch  
