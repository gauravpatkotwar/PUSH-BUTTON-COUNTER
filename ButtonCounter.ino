// Arduino sketch for debounced push-button counter with I2C LCD and Serial Monitor

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize I2C LCD (address 0x27, 16x2 display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;    // Push button on digital pin 2
const int ledPin = 13;      // LED for visual feedback
int buttonCount = 0;        // Counter for button presses
int buttonState = 0;        // Current button state
int lastButtonState = HIGH; // Previous button state (pull-up)
unsigned long lastDebounceTime = 0;  // Last time button was toggled
const unsigned long debounceDelay = 50; // Debounce delay in milliseconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Button pin with internal pull-up
  pinMode(ledPin, OUTPUT);          // LED pin as output
  digitalWrite(ledPin, LOW);        // LED off initially
  
  // Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("Button Counter Initialized");
  
  // Initialize I2C LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Button Counter");
  lcd.setCursor(0, 1);
  lcd.print("Count: 0");
}

void loop() {
  // Read button state
  int reading = digitalRead(buttonPin);

  // Detect state change
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset debounce timer
  }

  // Check if reading is stable
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      // Increment……

System: It looks like your response was cut off mid-sentence. I'll complete the artifact for you, ensuring the code and circuit diagram fully address the user's request to use an I2C LCD module with the Arduino Uno for displaying the button press count, alongside the Serial Monitor, with debouncing and LED feedback. I'll maintain the same artifact ID for the code as requested, since this is an update to the previous button counter system, and provide a new circuit diagram artifact to reflect the I2C LCD changes.

<xaiArtifact artifact_id="2477e83d-2dc3-407e-bc7d-8ba8aa05716e" artifact_version_id="85522cd5-05ef-4391-8daf-cb740a0735c1" title="ButtonCounterWithI2CLCD.ino" contentType="text/x-csrc">
// Arduino sketch for debounced push-button counter with I2C LCD and Serial Monitor

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize I2C LCD (address 0x27, 16x2 display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buttonPin = 2;    // Push button on digital pin 2
const int ledPin = 13;      // LED for visual feedback
int buttonCount = 0;        // Counter for button presses
int buttonState = 0;        // Current button state
int lastButtonState = HIGH; // Previous button state (pull-up)
unsigned long lastDebounceTime = 0;  // Last time button was toggled
const unsigned long debounceDelay = 50; // Debounce delay in milliseconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Button pin with internal pull-up
  pinMode(ledPin, OUTPUT);          // LED pin as output
  digitalWrite(ledPin, LOW);        // LED off initially
  
  // Initialize Serial Monitor
  Serial.begin(9600);
  Serial.println("Button Counter Initialized");
  
  // Initialize I2C LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Button Counter");
  lcd.setCursor(0, 1);
  lcd.print("Count: 0");
}

void loop() {
  // Read button state
  int reading = digitalRead(buttonPin);

  // Detect state change
  if (reading != lastButtonState) {
    lastDebounceTime = millis(); // Reset debounce timer
  }

  // Check if reading is stable
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      // Increment counter on button press (LOW due to pull-up)
      if (buttonState == LOW) {
        buttonCount++;
        digitalWrite(ledPin, HIGH); // Flash LED
        // Update Serial Monitor
        Serial.print("Button Pressed! Count: ");
        Serial.println(buttonCount);
        // Update LCD
        lcd.setCursor(0, 1);
        lcd.print("Count: ");
        lcd.print(buttonCount);
        lcd.print("   "); // Clear extra digits
        delay(100); // Brief LED flash
        digitalWrite(ledPin, LOW);
      }
    }
  }

  lastButtonState = reading; // Update last state
}
