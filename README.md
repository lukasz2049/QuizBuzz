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

## Hardware needed 
- 1 Arduino Mega (Due should also work fine, just keep in mind it's 3.3V)
- 1 RGB LED (optional) or 1 LED in a different color than those of the players.
- 2 buttons (Confirm and Cancel)
- 1 On/off switch or reset button
- 1 LCD Display (optional)
- 1 power supply (7-12V)
- Some wires ;)

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
