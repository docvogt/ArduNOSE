/*
Apr2012    MCVogt
Copyright(c) 2012 Purple Crayon Labs - for demonstration purposes.

This code demonstrates the two-fold functionality of the PCL-NH3 Ammonia Gas sensor with built-in multi-color
LED interface.  The PCL-NH3 sensor is designed for interfacing to the Arduino microcontrollers using one of
their standard Analog Input ports.  The PCL-NH3 is designed around the e2v brand NH3 sensing element with an ammonia
sensitivity from 0.1-100 ppm NH3 in Air.  The sensor conforms to the Arduino recommended wiring strategy and produces a voltage
within the range of the 0-5 VDC, 0-1023 10-bit analog input signal.  

The sensing element is wired to 3-pin port P1 with (S) Signal, (V) Power supply Voltage, and (G) signal Ground.  
Three bright colored SMD LEDs are wired to P2 and share the Ground with P1.  The LEDs are RED, GREEN, and BLUE and have
built-in 290 Ohm resistors so can be driven directly by the Arduino digital pins.  

Executing example code below samples the NH3 sensor and displays its raw unscaled value on the 
serial port.  The code tests the measured sensor value and compares it to programmer-defined thresholds for each LED and then
lights up each LED in Christmas-tree style depending upon the range and value of the readings, shutting the LED array off in-
between readings 1 second apart.

This code used a Toshiba Tecra M7 running Windows 7 using Serial Port COM4 to communicate with
an Arduino Uno R3 and an Arduino Mega2560.  

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
a second 3-pin cable connecting the NH3 sensor to Analog A0 (Pins).  

For all of this testing the PCL-NH3 was operated using an Arduino Uno with ONLY the USB cable for power, no external power was
needed and the code compiled and was uploaded many times without any communication error.  

Assistance with this code and operation of any of the PCL products can be requested at

info@purplecrayonlabs.us

Purple Crayon Labs, MN and IL
*/
//========================================================================
const int REDLEDthreshold = 1; // user set-able value for RED LED to turn on...
const int GREENLEDthreshold = 7; // user set-able value for RED LED to turn on...
const int BLUELEDthreshold = 17; // user set-able value for RED LED to turn on...
//========================================================================
int sensorPin = A0;   // select the input pin for the NH3 sensor...
int sensorValue = 0;  // variable to store the value coming from the sensor
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
  Serial.println("current raw NH3 reading is: " + String(sensorValue));
  delay(100);          
  //------------------------------------------------------------------------
  if (sensorValue > REDLEDthreshold ) digitalWrite(7, HIGH);   // set the RED LED on
  delay(100);          
  if (sensorValue > GREENLEDthreshold ) digitalWrite(6, HIGH);   // set the RED LED on
  delay(100);          
  if (sensorValue > BLUELEDthreshold ) digitalWrite(5, HIGH);   // set the RED LED on
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
