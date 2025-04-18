# 🔹 Project 01 – Blink LED using FreeRTOS Task

This project demonstrates how to create a basic FreeRTOS task on the ESP32 to blink the onboard LED at a fixed interval using `vTaskDelay()`.

## 🧠 Concepts Covered
- Task creation (`xTaskCreate`)
- Delay inside task (`vTaskDelay`)
- Basic FreeRTOS scheduling

## 🛠️ Hardware Required
- ESP32 Dev Board
- No additional hardware (uses onboard LED)

## 🖥️ Expected Serial Output
None (unless `Serial.println()` is added). LED should blink every 500ms.

## 📌 Notes
This is the most basic FreeRTOS project and acts as the foundation for multitasking with ESP32.
