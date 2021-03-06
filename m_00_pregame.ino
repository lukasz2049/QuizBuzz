/**
   Executed once, before entering the mode
*/
void BeforeModePregame() {
  disableAllLights();
}

/**
   Executed in a loop
*/
void ModePregame() {
  forEachPlayerBox(i) {
    if ( player[i]->isButtonPressed() && !player[i]->isActive() ) {
      Serial.println("Player " + String(i) + " has joined");
      player[i]->setStateActive(true);
      player[i]->setLights(HIGH);
    }
    player[i]->buzzIfButtonPressed();
  }

  if (0 == activePlayers) {
    return;
  }

  if (digitalRead(pinButtonConfirm) == LOW || activePlayers == connectedPlayerBoxes ) {
    changeMode(Modes::HOST);
  }
}

/**
   Executed once, after exiting the mode
*/
void AfterModePregame() {
  totalPlayers = activePlayers;
  scoreToWin = scoreToWin - totalPlayers;
  
  delay(500);
  disableAllBuzzers();
  soundGameStart();
}
