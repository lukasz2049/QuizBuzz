/**
 * Executed once, before entering the mode
 */
void BeforeModeQuestion() {
  EnableAllActiveLights();
  DisableAllBuzzers();
  questionNumber++;
}

/**
 * Executed in a loop
 */
void ModeQuestion() {
  delay(100);
  bool pressedButtons[maxPlayerBoxes];
  int pressedButtonsCounter = 0;
  for (i = 0; i < maxPlayerBoxes; i++) {
      if( !player[i]->isConnected() || !player[i]->isActive() ) {
        continue;
      }

      if (player[i]->isButtonPressed()) {
        pressedButtons[i] = true;
        pressedButtonsCounter++;
        selectedPlayer = i;
      } else {
        pressedButtons[i] = false;
      }
  }

  if( 0 == pressedButtonsCounter ) {
    return;
  }

  // There's a non-zero chance of two players pressing 
  // the button at the same time. Let's randomize it.
  while( 1 != pressedButtonsCounter ) {
    selectedPlayer = random(0, maxPlayerBoxes+1);
    // Not the best solution ever but works fine with only a few elements ;)
    if( pressedButtons[selectedPlayer] ) {
      pressedButtonsCounter = 1;
      player[selectedPlayer]->setBuzzer(HIGH);
    }
  }
  
  Serial.println("Player " + String(selectedPlayer) + " was fastest");
  changeMode(Modes::ANSWER);
}

/**
 * Executed once, after exiting the mode
 */
void AfterModeQuestion() {
  DisableAllLights();
  player[selectedPlayer]->questions++;
  player[selectedPlayer]->setLights(HIGH);
  player[selectedPlayer]->setBuzzer(HIGH);
  delay(500);
  player[selectedPlayer]->setBuzzer(LOW);
}
