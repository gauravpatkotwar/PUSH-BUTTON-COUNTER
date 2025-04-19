// Arduino sketch for a debounced push-button counter with Serial Monitor output

const int buttonPin = 2;    // Push button connected to digital pin 2
const int ledPin = 13;      // LED for visual feedback
int buttonCount = 0;        // Counter for button presses
int buttonState = 0;        // Current button state
int lastButtonState = HIGH; // Previous button state (pull-up)
unsigned long lastDebounceTime = 0;  // Last time button was toggled
const unsigned long debounceDelay = 50; // Debounce delay in milliseconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Button pin with internal pull-up
  pinMode(ledPin, OUTPUT);          // LED pin as output
  Serial.begin(9600);               // Start Serial Monitor at 9600 baud
  Serial.println("Button Counter Initialized");
  digitalWrite(ledPin, LOW);        // LED off initially
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
        Serial.print("Button Pressed! Count: ");
        Serial.println(buttonCount);
        delay(100); // Brief LED flash
        digitalWrite(ledPin, LOW);
      }
    }
  }

  lastButtonState = reading; // Update last state
}
