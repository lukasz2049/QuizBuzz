/**
   Executed once, before entering the mode
*/
void BeforeModeHost() {
  disableAllLights();
  disableAllBuzzers();
  setHostLight(HIGH);
}

/**
   Executed in a loop
*/
void ModeHost() {
  //Serial.println("Host");
  if (digitalRead(pinButtonConfirm) == LOW) {
    changeMode(Modes::QUESTION);
  }

  for (i = 0; i < maxPlayerBoxes; i++)
  {
    if (!player[i]->isActive()) {
      continue;
    }
    if (LOW == digitalRead(playerSelect[i])) {
      selectedPlayer = i;
      changeMode(Modes::ANSWER);
    }
  }
}

/**
   Executed once, after exiting the mode
*/
void AfterModeHost() {
  setHostLight(LOW);
}

