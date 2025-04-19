# PUSH-BUTTON-COUNTER

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: GAURAV SANJAY PATKOTWAR

*INTERN ID*: CT04DA584

*DOMAIN*: EMBEDDED SYSTEM

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTHOSH KUMAR

## Task Description: Designing a Simple Embedded System for Button Press Counting

The objective of this task is to design and implement a simple embedded system using a microcontroller to count and display the number of times a push button is pressed. The system incorporates debouncing to ensure accurate counting and displays the count on a Serial Monitor. The deliverables include the source code and a circuit diagram, with the implementation based on an Arduino Uno microcontroller for its accessibility and robust community support.

The embedded system is tasked with detecting button presses, incrementing a counter for each valid press, and outputting the count to a Serial Monitor for user visibility. A push button serves as the input device, connected to a digital pin on the Arduino. To provide visual feedback, an LED is included, which briefly lights up each time a button press is registered. The system must handle the mechanical noise inherent in push buttons, known as "bouncing," where a single press generates multiple rapid electrical transitions. Debouncing is implemented in software to filter these transitions and ensure each press increments the counter exactly once.

The Arduino Uno, powered by the ATmega328P microcontroller, is selected for its 16 MHz clock speed, 32 KB flash memory, and sufficient I/O pins. The chosen pin configuration uses digital pin 2 for the push button and pin 13 for the LED, leveraging the Arduino’s built-in LED for simplicity. The button is connected using the `INPUT_PULLUP` mode, eliminating the need for an external pull-up resistor by utilizing the microcontroller’s internal pull-up resistor. When pressed, the button connects the pin to ground, producing a LOW signal. The LED is connected through a 220-ohm current-limiting resistor to ground, ensuring safe operation.

The software, written in the Arduino C/C++ environment, initializes the pins and Serial Monitor (9600 baud) in the `setup()` function. The `loop()` function continuously reads the button’s state and implements debouncing by tracking state changes and enforcing a 50-millisecond delay to ignore transient signals. When a stable LOW state is detected (indicating a press), the counter increments, the LED flashes briefly (100 ms), and the updated count is printed to the Serial Monitor. The code maintains the last button state and debounce timestamp to ensure robust operation.

The circuit diagram details the connections: the push button links pin 2 to ground, and the LED connects pin 13 to ground via a 220-ohm resistor. The Arduino connects to a computer via USB for power and Serial Monitor output. This setup is breadboard-friendly, requiring minimal components, making it ideal for prototyping.

The system’s simplicity allows for educational use while demonstrating key embedded systems concepts: digital I/O, interrupt-free polling, software debouncing, and serial communication. Potential extensions include adding an LCD for standalone display or integrating wireless communication (e.g., via ESP8266) for remote monitoring. The design prioritizes reliability, using debouncing to prevent false counts, and accessibility, leveraging Arduino’s ecosystem for ease of implementation.
