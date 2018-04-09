void BeforeModeEnd() {
  /*
     Todo:
     1. Sort players by score
     2. Display score
  */
  for (i = 0; i < maxPlayerBoxes; i++) {

  }
}

void ModeEnd() {
  /*
     Todo:
     Allow Host to continue the game
  */
  if (LOW == digitalRead(pinButtonCenter)) {
    resetFunction();
  }
}

void AfterModeEnd() {

}

