/**
 * PlayerBox:
 * 
 * int button - pin
 * int lights - pin
 * int buzzer - pin
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
      pinButton = button;
      pinLights = lights;
      pinBuzzer = buzzer;
      
      pinMode(pinButton, INPUT_PULLUP);
      pinMode(pinLights, OUTPUT);
      pinMode(pinBuzzer, OUTPUT);

      digitalWrite(pinLights, HIGH);
      digitalWrite(pinBuzzer, LOW);

      stateConnected = false;
      if ( LOW == digitalRead(pinButton) ) {
        stateConnected = true;
        connectedPlayerBoxes++;
      }

    }
    boolean isActive() {
      if (!isConnected()) {
        return false;
      }
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
    void handleCorrectAnswer() {
      Serial.println("Good answer! :)");
      answersCorrect++;
      lastAnswerCorrect = true;
      soundCorrect();
    }
    void handleIncorrectAnswer() {
      Serial.println("Bad answer! :(");
      answersIncorrect++;
      lastAnswerCorrect = false;
      soundIncorrect();
      
      lives--;
      
      if(lives < 1) {
        stateActive = false;
        blinker(pinBuzzer, 20, 20, 10);
      }

    }
    void debug() {
      Serial.println( "button: " + String(pinButton) + ", lights: " + String(pinLights) + ", buzzer: " + String(pinBuzzer) );
    }
    int getPinButton() {
      return pinButton;
    }
    int getPinLights() {
      return pinLights;
    }
    int getPinBuzzer() {
      return pinBuzzer;
    }
};
