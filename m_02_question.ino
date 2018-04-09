/**
   Executed once, before entering the mode
*/
void BeforeModeQuestion() {
  enableAllActiveLights();
  questionNumber++;
  delay(100);

  // If players are already holding the buttons - let's choose a random one
  int randomPlayer = getRandomActivePlayer(true);
  if (-1 != randomPlayer) {
    selectedPlayer = randomPlayer;
    Serial.println("Player " + String(selectedPlayer) + " was luckiest");
    changeMode(Modes::ANSWER);
  }

}

/**
   Executed in a loop
*/
void ModeQuestion() {

  if (digitalRead(pinButtonCancel) == LOW) {
    changeMode(Modes::HOST);
  }

  for (i = 0; i < maxPlayerBoxes; i++) {
    if ( player[i]->isButtonPressed() ) {
      selectedPlayer = i;
      Serial.println("Player " + String(selectedPlayer) + " was fastest");
      changeMode(Modes::ANSWER);
    }
  }


}

/**
   Executed once, after exiting the mode
*/
void AfterModeQuestion() {
  disableAllLights();
  disableAllBuzzers();
}
