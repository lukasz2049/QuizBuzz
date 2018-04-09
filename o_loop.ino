void loop() {
  int loopStartMs = millis();
  switch (currentMode) {
    case Modes::PREGAME:
      ModePregame();
      break;
    case Modes::HOST:
      ModeHost();
      break;
    case Modes::QUESTION:
      ModeQuestion();
      break;
    case Modes::ANSWER:
      ModeAnswer();
      break;
    case Modes::END:
      ModeEnd();
      break;
    case Modes::TEST:
      ModeTest();
      break;
  }

  // Reset after 5s button hold
  while (LOW == digitalRead(pinButtonCenter) ) {
    if ( 5000 < ( millis() - loopStartMs) ) {
      resetFunction();
    }
  }
}
