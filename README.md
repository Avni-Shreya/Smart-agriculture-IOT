🌱 Smart-Agriculture-IOT
Arduino-based IoT system for automated irrigation using DHT11, soil moisture & rain sensors with real-time LCD display | C++, Arduino

📌 About The Project
This is a real hardware project built using Arduino Uno that automatically controls a water pump based on live soil moisture readings. It also monitors temperature, humidity, and rainfall — displaying everything on an LCD screen in real time.
No manual watering needed — the system decides on its own when to turn the motor ON or OFF.

⚙️ How It Works

Sensors continuously read soil moisture, temperature, humidity, and rain levels
If soil moisture drops below 15% → Motor turns ON (soil is too dry)
If soil moisture goes above 90% → Motor turns OFF (soil is wet enough)
All readings are displayed live on a 16x2 I2C LCD


🔌 Hardware Required
ComponentQuantityArduino Uno1DHT11 Temperature & Humidity Sensor1Soil Moisture Sensor (Analog)1Rain Sensor (Analog)116x2 LCD with I2C Module (0x27)15V Relay Module1Water Pump (5V)1Jumper WiresSeveralBreadboard1

🧩 Pin Connections
ComponentArduino PinDHT11 Data PinDigital Pin 4Soil Moisture SensorAnalog Pin A0Rain SensorAnalog Pin A1Relay ModuleDigital Pin 5I2C LCD (SDA)A4I2C LCD (SCL)A5

📚 Libraries Required
Install these from Arduino IDE → Tools → Manage Libraries:

LiquidCrystal_I2C — by Frank de Brabander
DHT sensor library — by Adafruit


▶️ How to Run

Connect all components as per the pin table above
Open smart_agriculture.ino in Arduino IDE
Go to Tools → Manage Libraries and install both libraries
Select Board: Arduino Uno
Select the correct Port (Tools → Port → COM3 or whichever shows)
Click Upload (the arrow button)
Once uploaded, the LCD will show:

      SMART
  AGRICULTURE
Then after 2 seconds it starts showing live readings.

💻 LCD Display
+----------------+
| T=32.5C  R=0   |
| S=12%  Motor=ON|
+----------------+
SymbolMeaningTTemperature in °CSSoil Moisture %RRelay/Rain readingMotorPump status ON/OFF

🔁 Pump Logic
cppif (mois < 15) → Motor ON   // Soil is dry, needs water
if (mois > 90) → Motor OFF  // Soil is wet, stop watering

