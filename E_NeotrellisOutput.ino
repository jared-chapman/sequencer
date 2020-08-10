void showLights(){
  /*
   * Loop through the lights[] array and show colors accordingly
   */
  for (int i = 0; i < 32; i++){
    trellis.setPixelColor(i, lights[i]);
  }
}
