int keyboardLightsDefault[] = {bg, bk, bk, bg, bk, bk, bk, bg,
                               wk, wk, wk, wk, wk, wk, wk, wk};

// These are the pitches that are selectable
// They will be multiplied by the octave
int notes[] = {-1, 1, 3, -1, 6, 8, 10, -1,
               0, 2, 4,  5, 7, 9, 11, 12};


void notePicker(int sequencePosition){
  /*
   * Shows keyboard instead of sequencer
   * Sets global var choosingNoteForPosition to the sequencer
   * position passed by the button press function that called this
   */
  
  for(int i = 0; i < sequenceLength; i++){
    lights[i + sequenceLightInitial] = keyboardLightsDefault[i];
  }
  choosingNoteForPosition = sequencePosition;
  state = 1;
}

void printKeyboard(){
  // Prints sequence data to console
  for (int i = 0; i < sequenceLength; i++){
    Serial.print("Position "); Serial.print(i); Serial.print(": "); Serial.println(sequenceNotes[i]);
  }
}
