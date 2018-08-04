/*
  PotBlink modifications MCVogt 31Jan2012
  Turns on LED on Port 13 to heartbeat w Pot-controlled delay between blinkblinks...
  
  PotBlink
  This example code is in the public domain.
 */
//declare these variables outside of setup so scope is global...
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin 

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
}

void loop() {
  digitalWrite(13, HIGH);   // set the LED on
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(100);              // wait for a second
  digitalWrite(13, HIGH);   // set the LED on
  delay(100);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off

  //control the value of the following delay using the POT input value...
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 2000);     // scale it to use it as a 0->2 Second (value between 0 and 2000 ms) 

  delay(val);              // wait for two seconds
}
