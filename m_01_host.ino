/**
   Executed once, before entering the mode
*/
void BeforeModeHost() {
  disableAllLights();
  disableAllBuzzers();
  setHostLight(HIGH);
  
  if ( checkForGameEnd() ) {
    changeMode(Modes::END);
  }
}

/**
   Executed in a loop
*/
void ModeHost() {
  //Serial.println("Host");
  if (digitalRead(pinButtonConfirm) == LOW) {
    changeMode(Modes::QUESTION);
  }

  if (digitalRead(pinButtonCenter) == LOW) {
    selectedPlayer = getRandomActivePlayer();
    changeMode(Modes::ANSWER);
    return;
  }

  forEachPlayerBox(i)
  {
    if ( !player[i]->isActive() ) {
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

