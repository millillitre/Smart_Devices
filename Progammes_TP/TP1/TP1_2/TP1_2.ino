int ledPin =  13;    // LED connected to digital pin 13
 
// The setup() method runs once, when the sketch starts
 
void setup()   {
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
  // initialize the digital pin as an output:
  pinMode(ledPin, OUTPUT);    
}
 
// the loop() method runs over and over again,
// as long as the Arduino has power
 
void loop()                    
{
  digitalWrite(ledPin, HIGH);   // set the LED on
  Serial.print(&quot;LED Status: ON\n&quot;);
  delay(1000);                  // wait for a second

  digitalWrite(ledPin, LOW);    // set the LED off
  Serial.print(&quot;LED Status: OFF\n&quot;);
  delay(1000);                  // wait for a second
}