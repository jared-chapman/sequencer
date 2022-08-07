void playMIDI(){
  for(int i = 0; i < 88; i++){
    trellis.noteOff(i, 64);
  }
  if (sequenceNotes[sequencePosition] > -1){
    trellis.noteOn(sequenceNotes[sequencePosition], 64);
  }
}

void controlChange() {
    /* Get a new sensor event */
  sensors_event_t event;
  accel.getEvent(&event);
  
  int y = 0;
  int z = 0;
  if (event.acceleration.y > 0) {
    y = event.acceleration.y * 10;
  }
  if (event.acceleration.z < 0) {
    z = -event.acceleration.z * 10;
  }
  if (y > 127) {
    y = 127;
  }
  if (z > 127){
    z = 127;
  }
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  trellis.controlChange(xCCy, y);
  trellis.controlChange(xCCz, z);
  trellis.sendMIDI();
}

void flipCcActive(){
  int ccToggleButtonNumber = 2;
  ccActive = !ccActive;
  if (ccActive){
    lights[ccToggleButtonNumber] = teal;
  } else {
    lights[ccToggleButtonNumber] = yellow;
  }
 
 
}
