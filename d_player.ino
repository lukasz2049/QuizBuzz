PlayerBox* player[maxPlayerBoxes];

#define forEachPlayerBox(i) for (i = 0; i < maxPlayerBoxes; i++)

// Functions that requires PlayerBox class

void disableAllBuzzers() {
  forEachPlayerBox(i) {
    player[i]->setBuzzer(LOW);
  }
}

void disableAllLights() {
  forEachPlayerBox(i) {
    player[i]->setLights(LOW);
  }
}

void enableAllActiveLights() {
  forEachPlayerBox(i) {
    if ( player[i]->isActive() ) {
      player[i]->setLights(HIGH);
    }
  }
}

/**
   Returns id of a random, active player
   Returns -1 if no player meets the conditions
*/
int getRandomActivePlayer(bool onlyPlayersWithPressedButton = false) {
  int listOfPlayers[maxPlayerBoxes];
  int numberOfPlayers = 0;

  forEachPlayerBox(i) {
    if ( !player[i]->isActive() ) {
      continue;
    }
    if ( onlyPlayersWithPressedButton && !player[i]->isButtonPressed() ) {
      continue;
    }
    Serial.println(String(i));
    listOfPlayers[numberOfPlayers] = i;
    numberOfPlayers++;
  }
  if (0 == numberOfPlayers) {
    return -1;
  }

  return listOfPlayers[random(numberOfPlayers)];
}

/*
   Todo - check for end-game rules:
   1. Only one player left (except when in 1-player mode)
   2. Some player scored N correct answers
*/

/**
   Checks if game should end now
*/
bool checkForGameEnd() {
  Serial.println("Active players: " + String(activePlayers));
  if ( 0 == activePlayers ) {
    return true;
  }

  forEachPlayerBox(i) {
    if ( player[i]->answersCorrect >= scoreToWin) {
      return true;
    }
  }

  return false;
}

