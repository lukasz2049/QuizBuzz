void setup() {
  Serial.begin(9600);
  Serial.println("");
  Serial.println("QuizBuzz for Arduino!");

  pinButtonConfirm = 8;
  pinButtonCancel = 12;
  pinHostLight = LED_BUILTIN;

  pinMode(pinButtonConfirm, INPUT_PULLUP);
  pinMode(pinButtonCancel, INPUT_PULLUP);

  // put your setup code here, to run once:
  player[0] = new PlayerBox(22, 23, 24, 25);
  player[1] = new PlayerBox(26, 27, 28, 29);
  player[2] = new PlayerBox(30, 31, 32, 33);
  player[3] = new PlayerBox(34, 35, 36, 37);
  // PlayerBox player[maxPlayerBoxes] = {};

  if (digitalRead(pinButtonCancel) == LOW) {
    silent = true;
    Serial.println("Vibrations and sounds are disabled now");
  }

  if (digitalRead(pinButtonConfirm) == LOW) {
    changeMode(Modes::TEST);
  } else {
    changeMode(Modes::PREGAME);
  }
}


