void DisableAllBuzzers() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    player[i]->setBuzzer(LOW);
  }
}

void DisableAllLights() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    player[i]->setLights(LOW);
  }
}

void EnableAllActiveLights() {
  for (i = 0; i < maxPlayerBoxes; i++)
  {
    if ( player[i]->isActive() ) {
      player[i]->setLights(HIGH);
    }
  }
}

/**
   Changes mode and runs before/after functions
   (After previous mode, Before new mode)
*/
void changeMode(int newMode) {
  // Wait until the button is released
  while (digitalRead(pinButtonConfirm) == LOW) {
    delay(10); // Debounce
  }

  // Prepare to changing the mode if needed
  switch (currentMode) {
    case Modes::PREGAME:
      AfterModePregame();
      break;
    case Modes::HOST:
      AfterModeHost();
      break;
    case Modes::QUESTION:
      AfterModeQuestion();
      break;
    case Modes::ANSWER:
      AfterModeAnswer();
      break;
    case Modes::TEST:
      AfterModeTest();
      break;
  }

  Serial.println();
  Serial.println("Entering mode " + String(newMode));

  // Prepare to changing the mode if needed
  switch (newMode) {
    case Modes::PREGAME:
      BeforeModePregame();
      break;
    case Modes::HOST:
      BeforeModeHost();
      break;
    case Modes::QUESTION:
      BeforeModeQuestion();
      break;
    case Modes::ANSWER:
      BeforeModeAnswer();
      break;
    case Modes::TEST:
      BeforeModeTest();
      break;
  }

  currentMode = newMode;
}

