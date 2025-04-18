# 🔹 Project 03 – Task Delay and Task Suspension Demo

This project shows how one task can suspend and resume another, demonstrating external task control in FreeRTOS.

## 🧠 Concepts Covered
- Task suspension (`vTaskSuspend`)
- Task resumption (`vTaskResume`)
- Task delay (`vTaskDelay`)

## 🛠️ Hardware Required
- ESP32 Dev Board

## 🖥️ Expected Serial Output
Task A is running... Task B suspending Task A Task B resuming Task A ...


## 📌 Notes
Task handles are used to control other tasks. Suspension is cooperative — only safe points are suspended.
