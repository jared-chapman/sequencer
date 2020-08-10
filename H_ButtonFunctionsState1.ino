// Between these lines are the functions to run when a button is pressed in state 0
//---------------------------------------------------------------------------------

void state1_0(){
  Serial.println("State 1 Button 0");
  playPause();
}

void state1_1(){
  Serial.println("State 1 Button 1");
}

void state1_2(){
  Serial.println("State 1 Button 2");
}

void state1_3(){
  Serial.println("State 1 Button 3");
}

void state1_4(){
  Serial.println("State 1 Button 4");
  String description = "Decrease Tempo";
  sequencerSpeed += 10;
}

void state1_5(){
  Serial.println("State 10 Button 5");
  String description = "Increase Tempo";
  sequencerSpeed -= 10;
}

void state1_6(){
  Serial.println("State 1 Button 6");
  octave--;
  sequencerLightControl();
}

void state1_7(){
  Serial.println("State 1 Button 7");
  octave++;
  sequencerLightControl();
}

void state1_8(){
  // Select Note
  Serial.println("State 1 Button 8");
  noteConfirmed();
  
}

void state1_9(){
  Serial.println("State 1 Button 9");
}

void state1_10(){
  Serial.println("State 1 Button 10");
}

void state1_11(){
  Serial.println("State 1 Button 11");
}

void state1_12(){
  Serial.println("State 1 Button 12");
}

void state1_13(){
  Serial.println("State 1 Button 13");
}

void state1_14(){
  Serial.println("State 1 Button 14");
}

void state1_15(){
  Serial.println("State 1 Button 15");
}

void state1_16(){
  // empty keyboard
  Serial.println("State 1 Button 16");
  sequenceNotes[choosingNoteForPosition] = -1;
  choosingNoteForPosition = -1;
  tempButtonPressed = -1;
  state = 0;
}

void state1_17(){
  // C#-Db
  // Give pitch and button number
  noteSelect(1, 17);
}

void state1_18(){
  // D#-Eb
  // Give pitch and button number
  noteSelect(3, 18);
}

void state1_19(){
  Serial.println("State 1 Button 19");
  
}

void state1_20(){
  // F#-Gb
  // Give pitch and button number
  noteSelect(6, 20);
}

void state1_21(){
  // G#-Ab
  // Give pitch and button number
  noteSelect(8, 21);
}

void state1_22(){
  // A#-Bb
  // Give pitch and button number
  noteSelect(10, 22);
}

void state1_23(){
  Serial.println("State 1 Button 23");
}

void state1_24(){
  // C
  
  // Give pitch and button number
  noteSelect(0, 24);
}

void state1_25(){
  // D
  // Give pitch and button number
  noteSelect(2, 25);
}

void state1_26(){
  // E
  // Give pitch and button number
  noteSelect(4, 26);
}

void state1_27(){
  // F
  // Give pitch and button number
  noteSelect(5, 27);
}

void state1_28(){
  // G
  // Give pitch and button number
  noteSelect(7, 28);
}

void state1_29(){
  // A
  // Give pitch and button number
  noteSelect(9, 29);
}

void state1_30(){
  // B
  // Give pitch and button number
  noteSelect(11, 30);
}

void state1_31(){
  // C+1
  // Give pitch and button number
  noteSelect(12, 31);
}

//---------------------------------------------------------------------------------
