// Graph Hot LED Vf graphs the forward voltage drop of an LED
// Copyright 2018, Paul H. Dietz

// LED Connections
#define PLUS A1
#define MEASURE A0

void setup() {
  Serial.begin(115200);       // Initialize serial communication
  pinMode(MEASURE, INPUT);
  pinMode(PLUS, OUTPUT);
  digitalWrite(PLUS, HIGH);   // Turn on the LED
}

void loop() {
  int cnt;
  long int sum = 0;

  // Sum 256 adc readings (to reduce adc noise)
  // Note: for loop repeats while condition is met
  // for ( initialize; condition; update)
  // cnt++ is same as cnt = cnt + 1
  for (cnt = 0; cnt < 256; cnt++) {
    sum = sum + analogRead(MEASURE);
  }
 
  Serial.println(sum);

  delay(10);
}
