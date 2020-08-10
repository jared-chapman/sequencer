void sequencerClock(){
  /*
   * Checks time against previous clock time
   * If the difference is greater than the sequencerSpeed, Tick, reset previous clock
   */
  int currentTime = millis();
  if (currentTime - previousClock > sequencerSpeed){
    if (playing){
      sequencerTick();
    }
    previousClock = currentTime;
  }
}

void sequencerTick(){
  /*
   * This function is called from the sequencerClock()
   * when the currentTime - previousTickTime > sequencerSpeed   * 
   */
  sequencerLightControl();
  sequenceAdvance();
  playMIDI();
}
