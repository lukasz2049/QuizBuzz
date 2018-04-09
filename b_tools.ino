// Basic Functions - Tools

/**
   Resets Arduino
*/
void(* resetFunction) (void) = 0;


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
    case Modes::END:
      AfterModeEnd();
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
    case Modes::END:
      BeforeModeEnd();
      break;
    case Modes::TEST:
      BeforeModeTest();
      break;
  }

  currentMode = newMode;
}

/**
   Host Light
*/
void setHostLight(uint8_t value) {
  digitalWrite(pinHostLight, value);
}

/**
   Blinks n times
   @todo use millis instead of delay
*/
void blinker(int pin, int n, int blinkInterval = 400, int pauseInterval = 250) {
  if (n < 1) {
    return;
  }

  uint8_t statePause = digitalRead(pin);
  uint8_t stateBlink = !statePause;

  delay(pauseInterval);

  for (i = 0; i < n; i++) {
    digitalWrite(pin, stateBlink);
    delay(blinkInterval);

    digitalWrite(pin, statePause);
    delay(pauseInterval);
  }
}
