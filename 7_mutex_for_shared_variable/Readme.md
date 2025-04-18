# 🔹 Project 07 – Mutex for Shared Variable Protection

This task uses a **mutex** to safely access a **shared counter variable**, preventing race conditions when multiple tasks increment it.

## 🧠 Concepts Covered
- Mutex (`xSemaphoreCreateMutex`)
- `xSemaphoreTake()` and `xSemaphoreGive()` for critical sections
- Protecting shared memory

## 🛠️ Hardware Required
- ESP32 Dev Board

## 🖥️ Expected Serial Output
Task 1 incremented counter to: 1

Task 2 incremented counter to: 2

....


## 📌 Notes
Mutexes are essential for data integrity when more than one task uses the same variable or structure. You learned how this differs from semaphores.
