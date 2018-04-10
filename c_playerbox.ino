/**
   PlayerBox:

   int button - pin
   int lights - pin
   int buzzer - pin
*/
class PlayerBox {
    int pinButton = 0;
    int pinLights = 0;
    int pinBuzzer = 0;

    bool stateConnected;
    bool stateActive = false;

  public:
    int questions = 0;
    int answersCorrect = 0;
    int answersIncorrect = 0;
    int lives = startingLives;
    bool lastAnswerCorrect = true;

    PlayerBox(int button, int lights, int buzzer) {
      this->pinButton = button;
      this->pinLights = lights;
      this->pinBuzzer = buzzer;

      pinMode(this->pinButton, INPUT_PULLUP);
      pinMode(this->pinLights, OUTPUT);
      pinMode(this->pinBuzzer, OUTPUT);

      digitalWrite(this->pinLights, HIGH);
      digitalWrite(this->pinBuzzer, LOW);

      this->stateConnected = false;
      if ( LOW == digitalRead(this->pinButton) ) {
        this->stateConnected = true;
        connectedPlayerBoxes++;
      }

    }
    boolean isActive() {
      if ( !this->isConnected() ) {
        return false;
      }
      return this->stateActive;
    }
    boolean isConnected() {
      return this->stateConnected;
    }
    boolean isButtonPressed() {
      return ( LOW != digitalRead(this->pinButton) && this->isConnected() );
    }
    void setBuzzer(uint8_t value) {
      if (silent) {
        return;
      }
      digitalWrite(this->pinBuzzer, value);
    }
    void setLights(uint8_t value) {
      digitalWrite(this->pinLights, value);
    }
    void setStateActive(boolean value) {
      if (this->stateActive == value) {
        return;
      }

      if (value) {
        activePlayers++;
      } else {
        activePlayers--;
      }

      this->stateActive = value;
    }
    void setStateConnected(boolean value) {
      this->stateActive = value;
    }
    void buzzIfButtonPressed() {
      if (silent || !this->isConnected()) {
        return;
      }
      digitalWrite(this->pinBuzzer, digitalRead(this->pinButton));
    }
    void lightIfButtonPressed() {
      if (!this->isConnected()) {
        return;
      }
      digitalWrite(this->pinLights, digitalRead(this->pinButton));
    }
    void handleCorrectAnswer() {
      Serial.println("Good answer! :)");
      this->answersCorrect++;
      this->lastAnswerCorrect = true;
      soundCorrect();
    }
    void handleIncorrectAnswer() {
      Serial.println("Bad answer! :(");
      this->answersIncorrect++;
      this->lastAnswerCorrect = false;
      soundIncorrect();

      this->lives--;

      if (lives < 1) {
        this->stateActive = false;
        blinker(pinBuzzer, 20, 20, 15);
      }

    }
    void debug() {
      Serial.println( "button: " + String(this->pinButton) + ", lights: " + String(this->pinLights) + ", buzzer: " + String(this->pinBuzzer) );
    }
    int getPinButton() {
      return this->pinButton;
    }
    int getPinLights() {
      return this->pinLights;
    }
    int getPinBuzzer() {
      return this->pinBuzzer;
    }
};
