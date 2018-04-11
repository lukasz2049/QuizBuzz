# QuizzBuzz
for Arduino (WIP)

## Modes

### 0: PREGAME
In this mode players are joining the game by pressing the button.  
Game begins (in _Host Mode_) either when the Host decides by pressing the **Confirm** button, or when buttons on all connected _Player Boxes_ were pressed.

TODO: Game settings

### 1: HOST
This mode is indicated by the **Host LED**.  
In this mode Host will be able to prepare before reading the question.  
- Press **Confirm** to continue to the _Question Mode_.
- Press **Center** button to select a random active player.
- Press **Player** button to select an active player.

### 2: QUESTION
This mode is indicated by all active _Player Boxes_ lighting up.  
The first person to press the button will be in the _Answer Mode_,
- Press **Cancel** to go back to the _Host Mode_.

### 3. ANSWER
This mode indicated by selected _Player Box_ ligting up.  
- Press **Confirm** to check the answer as correct. Player's score will be indicated by a number of light blinks.
- Press **Cancel** to check it as incorrect. Player's remaining lives will be indicated by a number of buzzer blinks. If a Player has no lives left a long, quieter buzz will occur.

Game will now return to the _Host Mode_ or change to the _End Mode_.

TODO: RGB LED on _Host Box_ to indicate the player.

### 9. END
This mode is not finished yet.  
This mode will be indicated by a rapid blinking of the Host Light.  
In this mode the lights of the winner(s) are turned on.  
Host may check the score of any player by pressing the corresponding player button.  

### 10: TEST
Debug mode.

## Modifiers
- Debug Mode: Press the **Confirm** button while powering on the machine.  
- Disable vibrations: Press the **Cancel** button while powering on the machine.  
- Reset: Press and hold the **Center** button for a few seconds.

## Hardware needed 
- 1 Arduino Mega (Due should also work fine, just keep in mind it's 3.3V)
- 1 RGB LED (optional) or 1 LED in a different color than those of the players.
- 2 buttons (Confirm and Cancel)
- 1 On/off switch or reset button
- 1 LCD Display (optional)
- 1 power supply (7-12V)
- Some wires ;)
- 1 SSD1306 screen (optional, **not supported yet**)
- 1 YX5300 mp3 module & a microSD card (optional, **not supported yet**)

Per player:
- 1 big colorful arcade button (look for "_60mm arcade buttons_" on Aliexpress or eBay)
- 1 color LED 
- 1 coin vibration motor 
- 2 S-Video female sockets (optional)
- 1 S-Video 4 pin cable (optional)
- 1 small colorful button (optional, for the Host)
- 1 transistor (optional) for driving an LED
- 1 transistor (optional) for driving a vibration motor

### Notes:
S-Video is in my opinion the best choice if you want for the buttons to be detachable. It has 4 pins: LED, button, motor & GND. Just make sure that the cable has separate wires 1 and 2.

A typical vibration motor works is designed for voltage from 1.5-2V up to 3.5-5V. Most of them are described as 3V units but should work with 5V just fine.  
Details: https://www.adafruit.com/product/1201  

Most, if not all, arcade buttons have 12V lights (just a regular color LED with a resistor). You'll need to replace the resistor if you want the full brightness. Alternatively you may keep the original resistors and, with a help of a transistor (which is recommended anyway), power it from a power supply (VIN pin).  

Keep in mind Arduino current limits:
- DC Current per I/O Pin:  up to 20 mA recommended, 40mA absolute max 
- Total DC Current from I/O Pins: 200 mA
- DC Current for 5V Pin:   400mA (USB), up to 900mA (external power supply)
- DC Current for 3.3V Pin: 50-150mA (shared with the 5V pin)
- DC Current for VIN Pin: limited by the power supply
