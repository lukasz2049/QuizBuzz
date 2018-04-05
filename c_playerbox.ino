class PlayerBox {
    /** @todo GND oddzielnie */
    int pinButton = 0;
    int pinBuzzer = 0;
    int pinLights = 0;
    int pinGround = 0;

    bool stateConnected;
    bool stateActive = false;

  public:
    int questions = 0;
    int answersCorrect = 0;
    int answersIncorrect = 0;

    PlayerBox(int button, int lights, int buzzer, int ground) {
      pinButton = button;
      pinLights = lights;
      pinBuzzer = buzzer;
      pinGround = ground;

      pinMode(pinBuzzer, OUTPUT);
      pinMode(pinLights, OUTPUT);
      pinMode(pinGround, OUTPUT);
      pinMode(pinButton, INPUT_PULLUP);

      digitalWrite(pinLights, HIGH);
      digitalWrite(pinBuzzer, LOW);

      stateConnected = false;
      if ( LOW == digitalRead(pinButton) ) {
        stateConnected = true;
        connectedPlayerBoxes++;
      }

    }
    boolean isActive() {
      return stateActive;
    }
    boolean isConnected() {
      return stateConnected;
    }
    boolean isButtonPressed() {
      return ( LOW != digitalRead(pinButton) && isConnected() );
    }
    void setBuzzer(uint8_t value) {
      if (silent) {
        return;
      }
      digitalWrite(pinBuzzer, value);
    }
    void setLights(uint8_t value) {
      digitalWrite(pinLights, value);
    }
    void setStateActive(boolean value) {
      if (stateActive == value) {
        return;
      }

      if (value) {
        activePlayers++;
      } else {
        activePlayers--;
      }

      stateActive = value;
    }
    void setStateConnected(boolean value) {
      stateActive = value;
    }
    void buzzIfButtonPressed() {
      if (silent || !isConnected()) {
        return;
      }
      digitalWrite(pinBuzzer, digitalRead(pinButton));
    }
    void lightIfButtonPressed() {
      if (!isConnected()) {
        return;
      }
      digitalWrite(pinLights, digitalRead(pinButton));
    }
    void debug() {
      Serial.println( "button: " + String(pinButton) + ", lights: " + String(pinLights) + ", buzzer: " + String(pinBuzzer) );
    }
};

PlayerBox* player[maxPlayerBoxes];
