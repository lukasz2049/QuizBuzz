void loop() {
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

  int startMs = millis();
  // Reset after 5s button hold
  while (LOW == digitalRead(pinButtonCenter) ) {
    if ( 6000 < ( millis() - startMs) ) {
      resetFunction();
    }
  }
}
