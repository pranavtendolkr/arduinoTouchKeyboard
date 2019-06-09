# Capacitive Keyboard

Turn an Arduino Uno into a keyboard which can send keypresses on touching a capacitive sensor

             
 ## How to:
 Download and install flip from atmel.  (https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/FLIP)

 1. Put Arduino in DFU mode.
      short pins 5-6 on the ICSP header near usb. Connect to computer. 
      ![Pins to short](http://2.bp.blogspot.com/-3NUsmpZn3CU/UjAZu5yS9BI/AAAAAAAADfQ/Xekuk1jNh4Y/s1600/ArduinoUno_R3_Front_450px.jpg)
    
      Once you remove short, it should get detected in device manager as atmel device 
      
      If it appears as a unknown device, install friver from `c:\Program Files (x86)\Atmel\Flip 3.4.7\usb\`
 2. open flip programmer, ctrl + U, open usb connection
 3. Flash [default arduino firmware](Arduino-usbserial-uno.hex).
 4. Disconnect. 
 5. upload program using IDE.
 6. Disconnect and connect in DFU mode
 7. Using Flip, flash the [keyboard firmware](Arduino-keyboard-0.3.hex). 
 
## Connections
* Pin 2 - sensor pin. 
* Pin 4 sense pin. 
*  connect 1M resistor between pin 2 and 4
* connect metal to pin 2 to sense touch.
*  Use total1 to set threshold, or time difference.
 
 
 ## References
 * http://mitchtech.net/arduino-usb-hid-keyboard/ -> TUTORIAL
 * https://github.com/nylen/auto-f1-presser -> FIRMWARE             
 * https://hester.mtholyoke.edu/idesign/SensorTouch.html  -> SENSOR LIBRARY
