# 🚀 ESP32 FreeRTOS Labs

This repository contains beginner-friendly to intermediate-level projects using **ESP32** and **FreeRTOS** with the **Arduino IDE**. Each example is modular, well-documented, and aimed at helping developers understand core RTOS concepts like multitasking, task synchronization, inter-task communication, and more.

> 🧠 These examples work **with just an ESP32 board and a USB cable** — no external sensors needed for the first 10 demos!

---

## 🔧 Requirements

- **ESP32 Dev Board**
- **Arduino IDE** with ESP32 board support installed
- USB cable for programming and Serial Monitor

---

## 📁 Project Structure

Each folder includes:
- `.ino` source file
- Description of the concept
- Serial output expectations
- Optional enhancements

---

## ✅ Project List (1–10)

| #  | Project Title                                  | Description |
|----|------------------------------------------------|-------------|
| 01 | **Blink LED using FreeRTOS Task**              | A simple task that toggles an onboard LED every 500ms using `vTaskDelay()`. |
| 02 | **Multiple Tasks with Different Priorities**   | Two tasks printing messages with different priorities to demonstrate FreeRTOS scheduler behavior. |
| 03 | **Task Delay and Task Suspension Demo**        | Task A prints periodically, and Task B suspends/resumes it to show task control. |
| 04 | **Inter-task Communication using Queues**      | Demonstrates message passing between a producer and a consumer task using FreeRTOS queues. |
| 05 | **Binary Semaphore for Button Press**          | Use a binary semaphore to trigger a task only when a button is pressed. *(Button required)* |
| 06 | **Counting Semaphore to Control Resource Access** | Simulates access control to a shared resource with limited availability using counting semaphores. |
| 07 | **Mutex for Shared Variable Protection**       | Prevent race conditions by protecting a shared counter variable using a mutex. |
| 08 | **Software Timer to Trigger Periodic Task**    | Demonstrates FreeRTOS software timers to run code at fixed intervals independent of task timing. |
| 09 | **UART Communication with FreeRTOS Tasks**     | Sends and receives serial messages using separate tasks for RX and TX over UART. |
| 10 | **Task Notifications (Lightweight Signaling)** | Uses `xTaskNotify()` to send signals between tasks without the overhead of queues or semaphores. |

---

## 🛠️ Getting Started

1. Clone the repo:
   ```bash
   git clone https://github.com/yourusername/esp32-freertos-labs.git
