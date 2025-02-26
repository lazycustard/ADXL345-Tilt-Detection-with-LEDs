# Tilt Detection with ADXL345 and LEDs

---

## 📌 Overview
This project uses an **ADXL345 accelerometer** to detect tilt in different directions and indicate movement using **LEDs**. The program reads acceleration values from the ADXL345 sensor and turns on LEDs based on the tilt direction.

---

## 🔧 Components Required
- Arduino Board
- ADXL345 Accelerometer
- 4 LEDs
- Resistors (220Ω for each LED)
- Jumper wires

---

## 🖥️ Circuit Diagram
- **ADXL345 Connections:**
  - VCC → 3.3V (or 5V depending on the module)
  - GND → GND
  - SDA → A4 (Arduino SDA)
  - SCL → A5 (Arduino SCL)
- **LED Connections:**
  - Left LED → Pin 3
  - Right LED → Pin 4
  - Forward LED → Pin 5
  - Backward LED → Pin 6

---

## 📝 Code Explanation
- The **Adafruit_ADXL345_Unified** library is used to interface with the sensor.
- The accelerometer is initialized in the **setup()** function.
- The **loop()** function continuously reads acceleration values and determines the tilt direction based on a defined threshold.
- LEDs are turned on accordingly:
  - Right LED → When tilted left
  - Left LED → When tilted right
  - Forward LED → When tilted forward
  - Backward LED → When tilted backward
- The acceleration values (X, Y, Z) are printed in the Serial Monitor for debugging.

---

## 🛠️ Installation & Setup
1. Install the **Adafruit ADXL345** library in the Arduino IDE:
   - Go to **Sketch** → **Include Library** → **Manage Libraries**.
   - Search for **Adafruit ADXL345** and install it.
2. Connect the **ADXL345 sensor** and **LEDs** as per the circuit diagram.
3. Upload the provided code to the **Arduino**.
4. Open the **Serial Monitor** (**9600 baud rate**) to view tilt data.

---

## 🎮 Usage
- Tilt the sensor in different directions and observe which LED lights up.
- Use the Serial Monitor to see real-time acceleration values.
- Modify the **tiltThreshold** value in the code to adjust sensitivity.

---

## 🚀 Future Improvements
- Add **OLED or LCD display** to show real-time acceleration values.
- Extend the project to control **robotic movements** based on tilt data.
- Develop a **wireless system** using Bluetooth or Wi-Fi for remote monitoring.

---

## 📝 License
This project is open-source and can be freely modified and shared.



