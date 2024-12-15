#include <LiquidCrystal_I2C.h>

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16x2 display

// Constants
const int analogPin = A0;         // Pin connected to the thermistor
const int seriesResistor = 10000; // Value of the pull-down resistor in ohms
const float nominalResistance = 10000; // Resistance of thermistor at 25°C
const float nominalTemperature = 25.0; // Temperature at nominal resistance (in Celsius)
const float bCoefficient = 3950;       // Beta coefficient of the thermistor
const float adcMax = 1023.0;           // Maximum ADC value (10-bit ADC)

void setup() {
  Serial.begin(9600);      // Initialize serial communication
  lcd.begin();             // Initialize the LCD (no arguments)
  lcd.backlight();         // Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
}

void loop() {
  int analogValue = analogRead(analogPin); // Read the analog value from the thermistor
  Serial.print("Analog Value: ");
  Serial.println(analogValue);

  // Check for valid analog reading
  if (analogValue > 0 && analogValue < 1023) {
    // Calculate resistance of the thermistor
    float resistance = seriesResistor / ((adcMax / analogValue) - 1);
    Serial.print("Resistance: ");
    Serial.println(resistance);

    // Calculate temperature in Celsius
    float tempC = 1.0 / (log(resistance / nominalResistance) / bCoefficient + (1.0 / (nominalTemperature + 273.15))) - 273.15;
    Serial.print("Temperature (C): ");
    Serial.println(tempC);

    // Convert temperature to Fahrenheit
    float tempF = (tempC * 1.8) + 32;
    Serial.print("Temperature (F): ");
    Serial.println(tempF);

    // Display temperatures on the LCD
    lcd.setCursor(0, 1);
    lcd.print("C: ");
    lcd.print(tempC, 1); // Display Celsius with 1 decimal place
    lcd.print("  F: ");
    lcd.print(tempF, 1); // Display Fahrenheit with 1 decimal place
  } else {
    Serial.println("Error: Invalid analog reading. Check wiring.");
    lcd.setCursor(0, 1);
    lcd.print("Check wiring!     ");
  }

  delay(1000); // Wait for 1 second before the next reading
}
