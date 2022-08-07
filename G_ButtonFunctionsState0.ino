//Functions to run when a button is pressed in state 0

void state0_0(){
  // Play/Pause
  Serial.println("State 0 Button 0");
  playPause();
}

void state0_1(){
  // Restart
  Serial.println("State 0 Button 1");
  sequencePosition = -1;
  sequencerLightControl();
}

void state0_2(){
  Serial.println("State 0 Button 2");
  flipCcActive();
}

void state0_3(){
  Serial.println("State 0 Button 3");
}

void state0_4(){
  Serial.println("State 0 Button 4");
  String description = "Decrease Tempo";
  sequencerSpeed += 10;
}

void state0_5(){
  Serial.println("State 0 Button 5");
  String description = "Increase Tempo";
  sequencerSpeed -= 10;
}

void state0_6(){
  Serial.println("State 0 Button 6");
  octave--;
  sequencerLightControl();
}

void state0_7(){
  Serial.println("State 0 Button 7");
  octave++;
  sequencerLightControl();
}

void state0_8(){
  Serial.println("State 0 Button 8");
}

void state0_9(){
  Serial.println("State 0 Button 9");
}

void state0_10(){
  Serial.println("State 0 Button 10");
}

void state0_11(){
  Serial.println("State 0 Button 11");
}

void state0_12(){
  Serial.println("State 0 Button 12");
}

void state0_13(){
  Serial.println("State 0 Button 13");
}

void state0_14(){
  Serial.println("State 0 Button 14");
}

void state0_15(){
  Serial.println("State 0 Button 15");
}

void state0_16(){
  Serial.println("State 0 Button 16");
  notePicker(0);
  //flip(0);
}

void state0_17(){
  Serial.println("State 0 Button 17");
  notePicker(1);
}

void state0_18(){
  Serial.println("State 0 Button 18");
  notePicker(2);
}

void state0_19(){
  Serial.println("State 0 Button 19");
  notePicker(3);
}

void state0_20(){
  Serial.println("State 0 Button 20");
  notePicker(4);
}

void state0_21(){
  Serial.println("State 0 Button 21");
  notePicker(5);
}

void state0_22(){
  Serial.println("State 0 Button 22");
  notePicker(6);
}

void state0_23(){
  Serial.println("State 0 Button 23");
  notePicker(7);
}

void state0_24(){
  Serial.println("State 0 Button 24");
  notePicker(8);
}

void state0_25(){
  Serial.println("State 0 Button 25");
  notePicker(9);
}

void state0_26(){
  Serial.println("State 0 Button 26");
  notePicker(10);
}

void state0_27(){
  Serial.println("State 0 Button 27");
  notePicker(11);
}

void state0_28(){
  Serial.println("State 0 Button 28");
  notePicker(12);
}

void state0_29(){
  Serial.println("State 0 Button 29");
  notePicker(13);
}

void state0_30(){
  Serial.println("State 0 Button 30");
  notePicker(14);
}

void state0_31(){
  Serial.println("State 0 Button 31");
  notePicker(15);
}