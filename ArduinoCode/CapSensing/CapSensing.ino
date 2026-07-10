// Capacitive sensing using Maxwell's method of intermittent currents
//
// Uses pin 8 for the sensing plate
// Integrating cap is placed across pins 8 and 9 (0.01 to 0.1 uF recommended)
//
// Note: This impacts all Port B pins (8-13)
//
// PORTB is the Port B output register. It determines high or low when outputing
// DDRB is the Port B data direction register. A 1 indicates output, 0 is input


// cap() returns the ratio of the integrating cap to the sense cap to ground on pin 8.
// The higher the capacitance, the lower the value.
int cap() {

  int cnt=0;
  // Discharge
  PORTB = B00000000;
  DDRB = B00000011;
  delayMicroseconds(3);

  // Charge
  DDRB = B00000001;
  PORTB = B00000001;

  while(PINB & B00000010) {
    // Release
    DDRB = B00000000;
  
    // Share
    DDRB = B00000010;
  
    // Release
    DDRB = B00000000;
  
    // Charge
    DDRB = B00000001;

    cnt++;
  }
  return cnt;
}

void setup() {
  Serial.begin(115200);
  bitSet(MCUCR, PUD);   // Disable input pullups
}

void loop() {
  Serial.println(cap());
  delay(20);
}
