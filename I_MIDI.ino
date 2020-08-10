void playMIDI(){
  for(int i = 0; i < 88; i++){
    trellis.noteOff(i, 64);
  }
  if (sequenceNotes[sequencePosition] > -1){
    trellis.noteOn(sequenceNotes[sequencePosition], 64);
  }
}
