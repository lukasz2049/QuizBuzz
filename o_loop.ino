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
    case Modes::TEST:
      ModeTest();
      break;
  }
}
