// Nitro (nitro0@naver.com)

unsigned long counts;
unsigned long previousMillis;
void impulse() {
  counts++;
  //Serial.println("Signal Detected"); // This code will print out when pin 2 get a signal.
}

#define LOG_PERIOD 10000 // Count speed (1000ms = 1sec)

void setup() {
  counts = 0;
  Serial.begin(9600);
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), impulse, FALLING); // External interrupts
  Serial.println("[Counter Started]");
}

void loop() { // Cycle
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > LOG_PERIOD) {
  previousMillis = currentMillis;
  Serial.println(counts);
  counts = 0;
  }
}
