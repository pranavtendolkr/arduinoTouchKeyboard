/*
 * 
 * References:  http://mitchtech.net/arduino-usb-hid-keyboard/ -> TUTORIAL
 *              https://github.com/nylen/auto-f1-presser -> FIRMWARE
 *              
 *              https://hester.mtholyoke.edu/idesign/SensorTouch.html 
 *              
 How to:
 1. Put Arduino in DFU mode.
      short pins 5-6 on the ICSP header near usb, connect to computer
      remove short. should get detected in device manager as atmel device
 2. open flip programmer, ctrl + U, open usb connection
 3. Flash default arduino firmware.
 4. Disconnect. 
 5. upload program using IDE.
 6. Disconnect and connect in DFU mode
 7. Using Flip, flash the keyboard firmware. 

 Connection: Pin 2 - sensor pin. 
 Pin 4 sense pin. 
 connect 1M resistor between pin 2 and 4
 connect metal to pin 2 to sense touch.

 Use total1 to set threshold, or time difference.
 
 */


#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2);

uint8_t buf[8] = { 
  0 };   /* Keyboard report buffer */


void setup() {
    Serial.begin(9600);
    delay(2000);
}

void loop() {
  long start = millis();
  long total1 = cs_4_2.capacitiveSensor(30); // takes the number of samples to consider.
  //more samples, more accurate the reading.

  // if the detection happens fast, someone is touching it. 
  // better value is threshold, total1, but that sometimes returns a negative value for errors
  if(millis() - start < 300 ){
      buf[2] = 16;    // 16 = M
      // keycodes can be found at https://www.insidegadgets.com/wp-content/uploads/2014/11/Hut1_11.pdf
      // Page 53
      Serial.write(buf, 8); // Send keypress  
      releaseKey();
  delay(2000);
  }
  
  

}


void releaseKey() 
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);  // Release key  
}
