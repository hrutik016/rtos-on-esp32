# 🔹 Project 09 – UART Communication with FreeRTOS Tasks

This task demonstrates **non-blocking UART communication** using two FreeRTOS tasks:
- One for sending
- One for receiving from Serial Monitor

## 🧠 Concepts Covered
- Task-based UART TX/RX
- `Serial.available()` and `Serial.readStringUntil()`
- Independent execution of communication tasks

## 🛠️ Hardware Required
- ESP32 Dev Board
- USB connection to PC

## 🖥️ Expected Serial Output
TX Task: Sending count 0
RX Task: Received -> hello


## 📌 Notes
You asked: “Is this UART via MicroUSB?” — Yes! The USB cable carries UART data via a USB-to-UART chip (e.g., CP2102). This is how `Serial` works on ESP32. You can also connect ESP32 to Arduino UNO using UART pins for real embedded comms.
