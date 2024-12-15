# Arduino Temperature Sensor (Thermistor Version)

## Description
This project is a temperature sensor system using an Arduino and a thermistor to measure temperature. It reads the temperature from the thermistor, converts it to Celsius and Fahrenheit, and displays it on an LCD screen. This can be used for various applications where temperature monitoring is required.

## Features
- Measures temperature using a thermistor.
- Displays the temperature in both Celsius and Fahrenheit on an LCD.
- Easy to set up and use with Arduino.
- Simple and reliable for temperature monitoring applications.

## Hardware Requirements
- **Arduino** (Elegoo Uno R3 used in this project)
- **Thermistor** (e.g., 10kΩ thermistor)
- **10kΩ Resistor**
- **16x2 LCD Display** (with I2C interface)
- **Breadboard and Jumper wires**
- **Power Source** (USB or external power supply)

### Wiring Setup
- **Thermistor**: One end connected to 5V (positive rail), the other end connected to **A0** pin on the Arduino.
- **10kΩ Resistor**: Connected between **A0** and **GND**.
- **LCD Display**: Connected to the Arduino using the **I2C interface** (SDA to A4, SCL to A5 for the Uno R3).

## Wiring Diagram
(Include a simple diagram or a reference to one showing how to connect the thermistor, resistor, and LCD to the Arduino.)

## Installation
1. Clone or download this repository to your local machine.
2. Open the Arduino IDE.
3. Go to **File > Open** and select the `Arduino-Temperature-Sensor_Thermistor_Version.ino` file.
4. Select the correct Arduino board and port from the **Tools** menu.
5. Upload the code to your Arduino board.

## Usage
- Once the code is uploaded, the LCD will show the temperature reading.
- The temperature will be displayed in both Celsius and Fahrenheit on the LCD.
  
## Code Explanation
- The thermistor is read through an analog input pin, and the value is converted to a resistance.
- The resistance is then converted to temperature using a formula based on the thermistor's characteristics.
- The temperature values are displayed on the LCD in Celsius and Fahrenheit.

## Troubleshooting
- If the LCD is not displaying correctly, check the wiring connections, especially the SDA and SCL pins for the I2C interface.
- If the temperature values appear incorrect, verify the thermistor’s wiring and the code for proper calibration.

## Contributing
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Create a new Pull Request.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
