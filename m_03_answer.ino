/**
   Executed once, before entering the mode
*/
void BeforeModeAnswer() {
  DisableAllBuzzers();
}

/**
   Executed in a loop
*/
void ModeAnswer() {
  player[selectedPlayer]->buzzIfButtonPressed();

  if (digitalRead(pinButtonConfirm) == LOW) {
    Serial.println("Good answer! :)");
    player[selectedPlayer]->answersCorrect++;
    changeMode(Modes::HOST);
  } else if (digitalRead(pinButtonCancel) == LOW) {
    Serial.println("Bad answer! :(");
    player[selectedPlayer]->answersIncorrect++;
    changeMode(Modes::HOST);
  }
}

/**
   Executed once, after exiting the mode
*/
void AfterModeAnswer() {
  player[selectedPlayer]->setBuzzer(LOW);
  Serial.println();
  Serial.println( "Current scores:" );
  for (i = 0; i < maxPlayerBoxes; i++) {
    Serial.print( "Player " + String(i) + ": " );
    Serial.print( String(player[i]->answersCorrect - player[i]->answersIncorrect) ) ;
    Serial.print( " (+" + String(player[i]->answersCorrect) + ", -" + String(player[i]->answersIncorrect) + ")" );
    Serial.println();
  }
}

