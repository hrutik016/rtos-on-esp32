# 🔹 Project 08 – Software Timer to Trigger Periodic Task

This project demonstrates **FreeRTOS software timers** — lightweight timers that execute a **callback function** periodically without creating a task.

## 🧠 Concepts Covered
- Software timer (`xTimerCreate`, `xTimerStart`)
- Callback-based periodic execution
- Timer auto-reload functionality

## 🛠️ Hardware Required
- ESP32 Dev Board

## 🖥️ Expected Serial Output
Timer started.


Timer Callback Triggered!

Timer Callback Triggered!

...


## 📌 Notes
You asked, "Can I print more?" — yes! The callback is like a mini-task that runs periodically. You can log counters, toggle LEDs, or monitor states here. Unlike `vTaskDelay()`, this doesn’t need a full task or loop.
