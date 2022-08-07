void loop() {
  trellis.tick();
  buttonHandler();
  sequencerClock();
  sequencerLightControl(); // too heavy?
  if (ccActive){
    controlChange();
  }
}