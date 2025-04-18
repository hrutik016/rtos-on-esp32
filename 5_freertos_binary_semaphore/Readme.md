# 🔹 Project 05 – Binary Semaphore for Button Press

This task shows how to use a **binary semaphore** to let an **interrupt service routine (ISR)** wake up a blocked task.

## 🧠 Concepts Covered
- `xSemaphoreGiveFromISR()` from button ISR
- `xSemaphoreTake()` to block the task
- Using GPIO and debounce logic in ISR

## 🛠️ Hardware Required
- ESP32 Dev Board
- Push button connected to GPIO 0 and GND

## 🖥️ Expected Serial Output
Button Press Detected!


## 📌 Notes
Make sure you connect the button between GPIO and GND and use **INPUT_PULLUP** mode. You must disconnect the button pin if it's being shared with upload/reset.
