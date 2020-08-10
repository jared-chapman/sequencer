// This creates an array of functions corresponding to 
// The trellis buttons
typedef void (*FunctionArray) ();
FunctionArray buttonArray0[] = 
  {
    state0_0,
    state0_1,
    state0_2,
    state0_3,
    state0_4,
    state0_5,
    state0_6,
    state0_7,
    state0_8,
    state0_9,
    state0_10,
    state0_11,
    state0_12,
    state0_13,
    state0_14,
    state0_15,
    state0_16,
    state0_17,
    state0_18,
    state0_19,
    state0_20,
    state0_21,
    state0_22,
    state0_23,
    state0_24,
    state0_25,
    state0_26,
    state0_27,
    state0_28,
    state0_29,
    state0_30,
    state0_31,
  };

FunctionArray buttonArray1[] = 
  {
    state1_0,
    state1_1,
    state1_2,
    state1_3,
    state1_4,
    state1_5,
    state1_6,
    state1_7,
    state1_8,
    state1_9,
    state1_10,
    state1_11,
    state1_12,
    state1_13,
    state1_14,
    state1_15,
    state1_16,
    state1_17,
    state1_18,
    state1_19,
    state1_20,
    state1_21,
    state1_22,
    state1_23,
    state1_24,
    state1_25,
    state1_26,
    state1_27,
    state1_28,
    state1_29,
    state1_30,
    state1_31,
  };


void buttonHandler(){
  /*
   * When a key is pressed run its corresponding function
   */
  while(trellis.available()){
    keypadEvent e = trellis.read();

    if (e.bit.EVENT == KEY_JUST_PRESSED){
      int key = e.bit.KEY;
      Serial.print(key); Serial.println(" pressed");
      if (state == 0){
        buttonArray0[key]();
      } else {
        if (state == 1){
          buttonArray1[key]();
          //delay(5);
        }
      }
    }
  }
}
