PlayerBox* player[maxPlayerBoxes];

// Functions that requires PlayerBox class

void disableAllBuzzers() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    player[i]->setBuzzer(LOW);
  }
}

void disableAllLights() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    player[i]->setLights(LOW);
  }
}

void enableAllActiveLights() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    if ( player[i]->isActive() ) {
      player[i]->setLights(HIGH);
    }
  }
}

/*
 * Todo - check for end-game rules:
 * 1. Only one player left (except when in 1-player mode)
 * 2. Some player scored N correct answers
 */

