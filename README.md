*ACS712 Current Sensor Project with ATtiny85

This project utilizes an ACS712 current sensor and an ATtiny85 microcontroller to measure electrical current and display the results on a 128x64 OLED screen.

•Components Required
To build this circuit, you will need the following components:
 * Microcontroller: IC ATtiny85
 * Sensor: ACS712 Current Sensor
 * Display: 128\times64 OLED Display
 * Voltage Regulator: IC 7805 (Converts 12V to 5V)
 * Capacitors:
   * 10uF (16/25V) - Used for decoupling. 
   * 1uF(16/25V)
 * Resistors: 10kohm (Pullup resistor)
 * Switch: Tactile push button (with debounce prevention)
 * Power Source: Battery (7V to 25V input 30V max). 

• Power Supply Configuration
The project is powered by a battery regulated by an IC 7805.
 * Regulation: The IC 7805 converts the input voltage to a stable 5V output.
 * Stability: Two 10uFcapacitors are used at the input and output terminals for stability and noise reduction.
 * Voltage Requirements:
   * Input Voltage: 7V to 25V.
   * Output Voltage: 5V DC (Regulated).
   * Note: The IC 7805 requires at least 7V input to regulate effectively.
7805 Pinout Connections
 * Pin 1: Connected to +ve terminal of the battery.
 * Pin 2: Connected to -ve terminal of the battery (Ground).
 * Pin 3: Provides the regulated 5V output.

• Wiring & Connections
The ATtiny85 acts as the "brain" of the project, reading the sensor and driving the display.
ATtiny85 Pin Connections
 * Pin 8 (Vcc): Connect to +5V.
 * Pin 4 (GND): Connect to Common Ground.
 * Pin 1 (Reset): Connect to a 10kohm pullup resistor (connected to +5V). A push-button connects this pin to the ground.
 * Pin 2 (ADC): Connected to the Output of the ACS712 sensor to read the sensor's voltage.
 * Pin 5 (SDA): Connected to the SDA pin on the OLED.
 * Pin 7 (SCL): Connected to the SCL pin on the OLED.
ACS712 Sensor Connections
 * Vcc: Connect to +5V.
 * GND: Connect to Common Ground.
 * OUT: Connects to ATtiny85 Pin 2.
 * Screw Terminals: Connected in series with the Load.
OLED Display Connections
 * Vcc: Connect to +5V.
 * GND: Connect to Ground.
 * SCL: Connect to ATtiny85 Pin 7.
 * SDA: Connect to ATtiny85 Pin 5.

• Sensor Specifications & Resolution
Different models of the ACS712 have different sensitivities and resolutions. Select the appropriate model for your load requirements.

| ACS712 Model | Max Current | Sensor Sensitivity | Resolution |

| ACS712-05B | ±5 Amps  | 185 mV/Amp | 26 mA |

| ACS712-20A | ±20 Amps | 100 mV/Amp | 49 mA |

| ACS712-30A | ±30 Amps | 66 mV/Amp  | 74 mA |

Note on Resolution: The resolution indicates the smallest change in current the ATtiny can detect. For example, if using the 20A model, the current must change by at least 49mA for the system to detect it.

• Programming
 * Hardware: Use an Arduino board to program the ATtiny85 IC.
 * Software: The code is written and uploaded using the Arduino IDE.

