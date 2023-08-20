int irPin = 5; // Choose an appropriate PWM pin

void setup() {
  pinMode(irPin, OUTPUT);
}

void loop() {
  analogWrite(irPin, 128); // 50% duty cycle (128 is half of the maximum value 255)
  delayMicroseconds(13); // Half of the carrier period for 38 kHz (26.3 microseconds)
  analogWrite(irPin, 0); // Turn off the IR signal
  delayMicroseconds(13); // Half of the carrier period for 38 kHz (26.3 microseconds)
}