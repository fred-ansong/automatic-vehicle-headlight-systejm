// Define pins
const int trigPin = 5;   // Ultrasonic sensor trigger pin
const int echoPin = 6;   // Ultrasonic sensor echo pin
const int led1 = 9;      // First LED pin
const int led2 = 10;     // Second LED pin
const int photoResistorPin = A0; // Photoresistor analog input pin

// Define constants
const int maxDistance = 100; // Maximum distance in cm to detect objects
const int minDistance = 10;  // Minimum distance for maximum dimming
const int lightThreshold = 800; // Threshold above which it's considered bright

void setup() {
    pinMode(trigPin, OUTPUT); // Set trigger pin as output
    pinMode(echoPin, INPUT);  // Set echo pin as input
    pinMode(led1, OUTPUT);    // Set LED 1 pin as output
    pinMode(led2, OUTPUT);    // Set LED 2 pin as output
    Serial.begin(9600);       // Start serial communication for debugging
}

void loop() {
    // Read the ambient light level
    int lightLevel = analogRead(photoResistorPin);
    
    // Print light level for debugging
    Serial.print("Light Level: ");
    Serial.println(lightLevel);

    // If it's bright outside, turn off the LEDs completely
    if (lightLevel > lightThreshold) {
        analogWrite(led1, 0);
        analogWrite(led2, 0);
    } else {
        // Send a short pulse to trigger the ultrasonic sensor
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        // Read the echo pin, which returns the duration of the pulse in microseconds
        long duration = pulseIn(echoPin, HIGH);

        // Convert duration to distance in cm
        int distance = duration * 0.034 / 2;

        // Print distance for debugging
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");

        // Calculate brightness based on distance
        int brightness;
        if (distance > maxDistance) {
            // If no object is detected, keep LEDs at full brightness
            brightness = 255;
        } else {
            // Map distance to LED brightness (closer object = lower brightness)
            brightness = map(distance, minDistance, maxDistance, 50, 255);
            brightness = constrain(brightness, 50, 255); // Ensure brightness stays in range
        }

        // Apply brightness to LEDs
        analogWrite(led1, brightness);
        analogWrite(led2, brightness);
    }

    // Small delay to stabilize readings
    delay(100);
}
