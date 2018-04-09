void setup() {
  Serial.begin(9600);
  Serial.println("");
  Serial.println("QuizBuzz for Arduino!");

  pinButtonCancel = 8;
  pinButtonConfirm = 9;
  pinButtonCenter = 10;
  pinHostLight = 11;

  pinMode(pinButtonConfirm, INPUT_PULLUP);
  pinMode(pinButtonCancel, INPUT_PULLUP);
  pinMode(pinButtonCenter, INPUT_PULLUP);
  pinMode(pinHostLight, OUTPUT);
  digitalWrite(pinHostLight, LOW);

  playerSelect[0] = 2;
  playerSelect[1] = 3;
  playerSelect[2] = 4;
  playerSelect[3] = 5;
  playerSelect[4] = 6;

  for (i = 0; i < maxPlayerBoxes; i++) {
    pinMode(playerSelect[i], INPUT_PULLUP);
  }

  // put your setup code here, to run once:
  player[0] = new PlayerBox(22, 23, 24);
  player[1] = new PlayerBox(26, 27, 28);
  player[2] = new PlayerBox(30, 31, 32);
  player[3] = new PlayerBox(34, 35, 36);
  player[4] = new PlayerBox(38, 39, 40);
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


