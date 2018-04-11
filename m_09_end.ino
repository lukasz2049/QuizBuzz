void BeforeModeEnd() {
  disableAllLights();
  disableAllBuzzers();

  int topScore = 0;
  int topPlayers[totalPlayers] = {-1};
  int totalTopPlayers = 0;

  forEachPlayerBox(i) {
    if ( player[i]->answersCorrect < topScore ) {
      continue;
    }
    if ( player[i]->answersCorrect == topScore ) {
      topPlayers[totalTopPlayers] = i;
      totalTopPlayers++;
    } else {
      topPlayers[0] = i;
      totalTopPlayers = 1;
      topScore = player[i]->answersCorrect;
    }
  }
  
  if( 0 == topScore ) {
      soundGameEndFail();
      Serial.println("Top score is ZERO.");
      Serial.println("It's all there; black and white, clear as crystal!");
      Serial.println("So you get~ NOTHING! You lose!! GOOD DAY , sir!");
      return;
  }
  
  soundGameEnd();
  for(i = 0; i < totalTopPlayers; i++) {
    int topPlayer = topPlayers[i];
    Serial.println("Player " + String(topPlayer) + " won!");
    player[topPlayer]->setLights(HIGH);
  }
}



void ModeEnd() {
  Serial.println("aaa");
  /*
     Todo:
     Allow Host to continue the game?
  */
  forEachPlayerBox(i)
  {
    if ( !player[i]->isConnected() ) {
      continue;
    }
    if (LOW == digitalRead(playerSelect[i])) {
      player[i]->showScore();
    }
  }
  
  if (LOW == digitalRead(pinButtonCenter)) {
    resetFunction();
  }
}

void AfterModeEnd() {
  
}

