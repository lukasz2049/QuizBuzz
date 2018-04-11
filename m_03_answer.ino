/**
   Executed once, before entering the mode
*/
void BeforeModeAnswer() {
  Serial.println("Player " + String(selectedPlayer) + " is answering");
  player[selectedPlayer]->questions++;
  player[selectedPlayer]->setLights(HIGH);
  player[selectedPlayer]->setBuzzer(HIGH);
  delay(500);
  player[selectedPlayer]->setBuzzer(LOW);

}

/**
   Executed in a loop
*/
void ModeAnswer() {
  player[selectedPlayer]->buzzIfButtonPressed();

  if (digitalRead(pinButtonConfirm) == LOW) {
    player[selectedPlayer]->handleCorrectAnswer();
    changeMode(Modes::HOST);
  } else if (digitalRead(pinButtonCancel) == LOW) {
    player[selectedPlayer]->handleIncorrectAnswer();
    changeMode(Modes::HOST);
  }
}

/**
   Executed once, after exiting the mode
*/
void AfterModeAnswer() {
  player[selectedPlayer]->setBuzzer(LOW);
  player[selectedPlayer]->setLights(LOW);

  if ( player[selectedPlayer]->lastAnswerCorrect ) {
    player[selectedPlayer]->showScore();
  } else {
    player[selectedPlayer]->showLives();
  }

  Serial.println();
  Serial.println( "Current scores:" );
  forEachPlayerBox(i) {
    Serial.print( "Player " + String(i) + ": " );
    Serial.print( String(player[i]->answersCorrect - player[i]->answersIncorrect) ) ;
    Serial.print( " (+" + String(player[i]->answersCorrect) + ", -" + String(player[i]->answersIncorrect) + ")" );
    Serial.println();
  }

  delay(500);

}

