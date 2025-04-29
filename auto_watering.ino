const int sensorPin = A0;     // Soil sensor pin
const int relayPin = 7;       // Relay control pin
const int threshold = 600;    // Tune as needed

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int value = analogRead(sensorPin);
  Serial.println(value); // Check reading in Serial Monitor

  if (value > threshold) {
    // Soil is dry
    digitalWrite(relayPin, LOW);   // Pump ON (relay active LOW)
  } else {
    // Soil is wet
    digitalWrite(relayPin, HIGH);  // Pump OFF
  }

  delay(1000); // 1 sec delay
}
