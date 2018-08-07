/*
Apr2012    MCVogt
Copyright(c) 2012 Purple Crayon Labs - for demonstration purposes.

This code demonstrates the two-fold functionality of the Purple Crayon Labs (PCL)-NH3 Ammonia Gas sensor with built-in multi-color
LED interface.  The PCL-NH3 sensor is designed for interfacing to the Arduino microcontrollers using one of
their standard Analog Input ports.  The PCL-NH3 is designed around the e2v brand NH3 sensing element with an ammonia
sensitivity from 0.1-100 ppm NH3 in Air.  The sensor conforms to the Arduino recommended wiring strategy and produces a voltage
within the range of the 0-5 VDC, 0-1023 10-bit analog input signal.  

e2v NH3 sensor 
gas concentration        10-bit digital value        output 0-5VDC signal
-----------------        --------------------        --------------------
0.1 - 100 ppm             0 - 1023   (10-bit A/D)      0 - 5.0

The sensing element is wired to 3-pin port P1 with (S) Signal, (V) Power supply Voltage, and (G) signal Ground.  
Three bright colored SMD LEDs are wired to P2 and share the Ground with P1.  The LEDs are RED, GREEN, and BLUE and have
built-in 290 Ohm resistors so can be driven directly by the Arduino digital pins.  

Executing example code below samples the NH3 sensor and trnasmits its raw unscaled value on the 
serial port.  The code tests the measured sensor value and compares it to programmer-defined thresholds for each LED and then
lights up each LED in Christmas-tree style depending upon the range and value of the readings, shutting the LED array off in-
between readings 1 second apart, so the operator can tell the device is functioning by the "heartbeat" of the LED array.  

This code used on a   Toshiba Tecra M7   running   Windows 7   using Serial Port COM4 to communicate with
both/either an Arduino Uno R3 and/or an Arduino Mega2560 R3.  

For this sample code the PCL-NH3 was wired up as shown below.

======== PL2 ======== PL1 ========

   LED1 LED2 LED3    Sig +5V Gnd
    |    |    |       |   |   |
    |    |    |       |   |   |
    |    |    |       |   |   |
   D7   D6   D5      A0S A0V A0G

===================================

Where LED1, LED2, and LED3 are the colored LEDs on the PCL-NH3, and D7, D6, and D5 are Arduino digital pins 7, 6, and 5.
A0S, A0V, and A0G are the 3 pins associated with Arduino Analog port A0.  

The PCL-NH3 is most easily used with the Arduino Sensor Shield V4, with one 3-pin cable connecting all three of the LEDs and
a second 3-pin cable connecting the NH3 sensor to Analog port A0 (Pins).  

For all of this testing the PCL-NH3 was operated using an Arduino Uno with ONLY the USB cable for power, no external power was
needed and the code compiled and was uploaded many times without any communication error.  

Assistance with this code and operation of any of the PCL products can be requested at

info@purplecrayonlabs.us
Purple Crayon Labs, MN and IL
*/

/*
REVISION NOTES IN STACK FASHION NEWEST AT TOP

2018Aug06 mcvogt
3rd set of changes...  Installed Arduino extension to VSCode FROM MICROSOFT!!!
and now ALL of my reported bugs and errors are gone (following the reload of the editor
) because now VSCode understands my Arduino syntax... next, figger out how to add/connect
the Arduino compiler....  after we merge this meaningless change...

2nd set of edits this evening.. more monir typos.. .and edited the print statement....
these are changes madeon mikes PC in a New clone/download of the github repo...

minor typo corrections and edits to this main .ino file
set BLUELED threshold to be '0' so it becomes a power heartbeat, set GREENLED threshold to a low nominal value of 10, and
the REDLED threshold to a high concern value of 200.   BLUE will always get pulsed, GREEN will get pulsed when NH3 is detected
but non-problematic, and RED will get pulsed when there is a high enough concentration for concern (1/5 of FSL or 20ppm)

2018Aug05 mcvogt
as of 2018Aug the code is being maintained on Github

this code sets the REDLED threshold the lowest, it will go off first, then GREENLED then BLUEELD.  this might
not be the most intuitive way to use the LEDs...  BLUELED might be set at 0 and used for a 'powered up' indicator
and then GREEN set for low tolerable levels of NH3 and RED an indicator of concern....
making these changes will be an exercise in Github.

*/

//========================================================================
const int REDLEDthreshold = 200; // user set-able value for RED LED to turn on...
const int GREENLEDthreshold = 10; // user set-able value for GREEN LED to turn on...
const int BLUELEDthreshold = 0; // user set-able value for BLUE LED to turn on...
//========================================================================
int sensorPin = A0;   // select the input pin for the NH3 sensor... 
// 'port' A0 on the shield provides +5V and GND on adjacent pins...
int sensorValue = 0;  // iniialize variable to store the value coming from the sensor
//========================================================================
void setup() {                
  // initialise serial port for 115200 baud...
  Serial.begin(115200);
  // initialize the digital pins as an output.
  pinMode(5, OUTPUT); //RED LED... 
  pinMode(6, OUTPUT); //BLUE LED...    
  pinMode(7, OUTPUT); //GREEN LED...
}
//========================================================================
void loop() {
  //------------------------------------------------------------------------
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  //------------------------------------------------------------------------
  Serial.println("Mike, current raw NH3 reading is: " + String(sensorValue)); // will be between 0 and 1023
  delay(100);          
  //------------------------------------------------------------------------
  if (sensorValue > REDLEDthreshold ) digitalWrite(7, HIGH);   // set the RED LED on
  delay(100);          
  if (sensorValue > GREENLEDthreshold ) digitalWrite(6, HIGH);   // set the GREEN LED on
  delay(100);          
  if (sensorValue >= BLUELEDthreshold ) digitalWrite(5, HIGH);   // set the BLUE LED on
   // note - Not nested 'ifs', all, any, or none may be satisfied...
  //------------------------------------------------------------------------
  delay(200);          
  //------------------------------------------------------------------------
  digitalWrite(7, LOW);    // set the LED off
  digitalWrite(6, LOW);    // set the LED off
  digitalWrite(5, LOW);    // set the LED off
  //------------------------------------------------------------------------
  delay(200);          
  //------------------------------------------------------------------------
}
//========================================================================

