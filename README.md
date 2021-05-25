# Digital_Stop_Watch
This is a digital stop watch with start, stop and reset options. This embedded project is developed using Arduino-Uno with online 3D modeling program Tinkercad.

#API Required

pinMode(pin, mode) - Configures the specified pin to either input or output.
  - pin: the Arduino pin number to set the mode of.
  - mode: INPUT, OUTPUT, or INPUT_PULLUP.
  - 
digitalWrite(pin, value) - Write a HIGH or a LOW value to a digital pin.
  - pin: the Arduino pin number.
  - value: HIGH or LOW.
  - 
delay(ms) - Pauses the program for the amount of time (in milliseconds)
  - ms: the number of milliseconds to pause.
  - 
digitalRead(pin) - Reads the value from a specified digital pin, either HIGH or LOW.
  - pin: the Arduino pin number.

millis() - To record number of milliseconds passed since the current program began the execution.

#Instructions followed

This project is to develop a digital stop watch with start/stop and reset option. This system consist of three 7-segment LED unit to display the timing in milliseconds precision.
First and second 7-segment LED display seconds value
The last 7-segment LED display milliseconds value
Use of slide switch to start/stop the counting (HIGH-Start, LOW-Stop)
Use push button to reset the counting to initial value (HIGH-Reset)
Once it reaches it’s maximum counting, continue again with initial value

#Result

Simulated and verified this logic on Arduino Uno using Tinkercad circuits simulator.
