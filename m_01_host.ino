/**
 * Executed once, before entering the mode
 */
void BeforeModeHost() {
  DisableAllLights();
  digitalWrite(pinHostLight, HIGH);
}

/**
 * Executed in a loop
 */
void ModeHost() {
  //Serial.println("Host");
  if(digitalRead(pinButtonConfirm) == LOW) {
    changeMode(Modes::QUESTION);
  }
}

/**
 * Executed once, after exiting the mode
 */
void AfterModeHost() {
  digitalWrite(pinHostLight, LOW);
}

