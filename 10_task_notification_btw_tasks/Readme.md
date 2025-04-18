# 🔹 Project 10 – Task Notifications for Light Signaling Between Tasks

This task uses **FreeRTOS task notifications** — a faster alternative to semaphores — for **lightweight one-to-one signaling** between two tasks.

## 🧠 Concepts Covered
- `xTaskNotifyGive()` to send a signal
- `ulTaskNotifyTake()` to wait for it
- Non-blocking, zero-overhead IPC

## 🛠️ Hardware Required
- ESP32 Dev Board

## 🖥️ Expected Serial Output
Sender Task: Sending notification...

Receiver Task: Got notification!


## 📌 Notes
You asked why we use this — it's faster and lighter than a queue or semaphore when you just want to send a "ping" or signal. This is great for real-time flags or task wakeups.
