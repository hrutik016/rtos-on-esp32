# 🔹 Project 06 – Counting Semaphore to Control Resource Access

This task simulates **resource control** using a **counting semaphore**, limiting how many tasks can access a shared resource simultaneously.

## 🧠 Concepts Covered
- Counting semaphore (`xSemaphoreCreateCounting`)
- Access control for shared components
- Simulating real-world resource constraints (e.g., 2 printers)

## 🛠️ Hardware Required
- ESP32 Dev Board

## 🖥️ Expected Serial Output
Task 1 accessing resource... Task 2 accessing resource... Task 3 waiting... ...


## 📌 Notes
We assume a logical resource (not physical) to demonstrate task blocking when all "slots" are in use. You asked what the resource is — in this example, it's a **simulated limited service**.
