/**
   Executed once, before entering the mode
*/
void BeforeModeTest() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    if ( player[i]->isConnected() ) {
      Serial.println("Player's " + String(i) + " box connected");
    } else {
      Serial.println("Player's " + String(i) + " box NOT connected");
      player[i]->setLights(LOW);
      player[i]->setBuzzer(LOW);
      player[i]->setStateConnected(false);
    }
  }
}

/**
   Executed in a loop
*/
void ModeTest() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    player[i]->buzzIfButtonPressed();
    player[i]->lightIfButtonPressed();
    if (player[i]->isButtonPressed()) {
      Serial.println(String(i));
    }
  }

  if (digitalRead(pinButtonConfirm) == LOW) {
    changeMode(Modes::PREGAME);
  }
}

/**
   Executed once, after exiting the mode
*/
void AfterModeTest() {

}
