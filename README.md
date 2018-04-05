# QuizzBuzz
for Arduino (WIP)

## Modes

### 0: PREGAME
In this mode players are joining the game by pressing the button.  
Game begins (in _Host Mode_) either when the Host decides by pressing the **Confirm** button, or when buttons on all connected _Player Boxes_ were pressed.

### 1: HOST
This mode is indicated by the **Host LED**.  
In this mode Host will be able to prepare before reading the question.  
Press **Confirm** to continue to the _Question Mode_.

### 2: QUESTION
This mode is indicated by all active _Player Boxes_ lighting up.  
The first person to press the button will be in the _Answer Mode_,

### 3. ANSWER
This mode indicated by selected _Player Box_ ligting up.  
**Confirm** to check the answer as correct, **Cancel** to check it as incorrect.
After checking the answer game will return to the _Host Mode_
TODO: RGB LED on _Host Box_ to indicate the player.

### 10: TEST
Debug mode.

## Modifiers
-Debug Mode: Press the **Confirm** button while powering on the machine.  
-Disable vibrations: Press the **Cancel** button while powering on the machine.  
