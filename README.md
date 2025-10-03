# 🤖 Two-Wheel Robot Controlled by Chatbot

![Python](https://img.shields.io/badge/python-3.9%2B-blue.svg)
![RaspberryPi](https://img.shields.io/badge/RaspberryPi-4-red.svg)
![Arduino](https://img.shields.io/badge/Arduino-DUE%20Nano-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)  

---

## 📝 Project Description  
This project is a **two-wheel robot** controlled by a **chatbot interface**.  
The flow is simple:  

1. 🖥️ **PC** → A chatbot interprets user commands in natural language and translates them into robot instructions.  
2. 🍓 **Raspberry Pi 4** → Forwards the instructions to the Arduino over serial.  
3. 🔌 **Arduino DUE Nano** → Controls two FS90R continuous servos (left & right wheels) and executes commands (move forward, backward, turn).  
4. 🚦 LEDs indicate status:  
   - 🟥 Red = error / unknown command  
   - 🟩 Green = turning  
   - 🟨 Yellow = moving forward/backward  

---

## ⚙️ Features
- 💬 **Natural language control** via chatbot (e.g. *"Turn left 90° then move forward 10cm"*)  
- 🛠️ **Command translation** into robot actions:  
  - `AVx` → move forward (10cm × x)  
  - `REx` → move backward (10cm × x)  
  - `TGx` → turn left (10° × x)  
  - `TDx` → turn right (10° × x)  
  - `NRF` → do nothing  
- 🔄 Serial communication between PC → Raspberry Pi → Arduino  
- ⚡ LED status feedback  
- 🏎️ Smooth movement with continuous servos  

---

## 📂 Repository structure
```bash
├── pc/
│   └── chatbot_control.py     # Python script sending instructions to RPi
│
├── rpi/
│   └── serial_forward.py      # Raspberry Pi script sending commands to Arduino
│
├── arduino/
│   └── robot_control.ino      # Arduino code for motor + LED control
│
├── LICENSE
└── README.md
