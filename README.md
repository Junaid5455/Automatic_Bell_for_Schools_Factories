# ⏰ Automatic Bell System Using DS1307 RTC and ATmega328

This project is a simple **automatic bell system** designed for use in schools, factories, or other scheduled environments. It utilizes an **ATmega328 microcontroller** (e.g., Arduino Uno) and a **DS1307 Real-Time Clock (RTC)** module to ring a bell at pre-defined times. The bell schedule can be set dynamically via the **Serial Monitor**.

---

## 🛠 Features

- Real-time timekeeping with the DS1307 RTC
- Bell triggers at specific time(s) set by the user
- Time-based control using Arduino's `millis()` for non-blocking logic
- User-friendly time input over the Serial Monitor
- Flexible and easy to modify

---

## 🔌 Hardware Required

- Arduino Uno (or any ATmega328-based board)
- DS1307 RTC Module (with backup coin cell battery)
- Buzzer or Relay Module connected to a bell
- Jumper wires
- Breadboard (optional)

---

## ⚙️ Circuit Diagram

```
DS1307 RTC       Arduino UNO
-----------      -----------
VCC      --->    5V  
GND      --->    GND  
SDA      --->    A4  
SCL      --->    A5  

Bell/Buzzer ---> Pin 10 (via relay or transistor for high current load)
```

---

## 📦 Library Requirements

Install the following library via Arduino Library Manager:

- **RTClib** by Adafruit

```cpp
#include "RTClib.h"
```

---

## 🚀 Getting Started

1. **Connect the hardware** as shown in the diagram above.
2. **Upload the sketch** from `bell_system.ino` to your Arduino.
3. **Open the Serial Monitor** (9600 baud).
4. To set the bell ringing time, input the time string in the following format:

```
HH,MM;SS:MINHUM
```

Example:
```
08,30;00:50
```

This will ring the bell at **08:30:00**, and store the "minhum" value `50` (can be used for extended features like tracking or humidity triggers).

---

## 🔔 How It Works

- The DS1307 keeps the current time.
- Every second, the Arduino reads and prints the time.
- If the current time matches the user-set time (`ht, mt, st`), it activates the bell for 5 seconds using `digitalWrite`.
- Time can be reset at any point via Serial input.

---

## 📝 Customization

- You can adjust the **bell duration** by changing `delay(5000)` to your preferred ringing duration.
- The `minhum` variable is available for additional features such as logging or environmental control.

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 🙌 Acknowledgments

- [Adafruit RTClib](https://github.com/adafruit/RTClib)
- Arduino community for awesome open-source libraries

..........................................................................................................................................................................................
JUNAID SHABEER Experimental Physicist & IoT Developer.... LinkedIn:- www.linkedin.com/in/junaid-shabeer-machine-learning-physicist-b860a4285
