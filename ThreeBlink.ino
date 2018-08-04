/*
Apr2012    MCVogt
This code uses a Toshiba Tecra M7 running Windows 7 using Serial Port COM4 to communicate with
an Arduino Uno...
*/

int sensorPin = A0;   // select the input pin for the NH3 sensor...
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {                
  Serial.begin(115200);

  // initialize the digital pins as an output.
  pinMode(5, OUTPUT); //RED LED... 
  pinMode(6, OUTPUT); //BLUE LED...    
  pinMode(7, OUTPUT); //GREEN LED...
}

void loop() {
  digitalWrite(7, HIGH);   // set the RED LED on
  delay(100);              // wait for a second
  digitalWrite(7, LOW);    // set the LED off
  delay(100);              // wait for a second

  digitalWrite(6, HIGH);   // set the GREEN LED on
  delay(100);              // wait for a second
  digitalWrite(6, LOW);    // set the LED off
  delay(100);              // wait for a second

  digitalWrite(5, HIGH);   // set the BLUE LED on
  delay(100);              // wait for a second
  digitalWrite(5, LOW);    // set the LED off
  delay(100);              // wait for a second

  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    

  Serial.println("current raw NH3 reading is: " + String(sensorValue));
  delay(1000);          
}
