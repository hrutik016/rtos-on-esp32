# 🔹 Project 04 – Inter-task Communication using Queues

This project demonstrates how to pass data from one FreeRTOS task (Producer) to another (Consumer) using a queue.

## 🧠 Concepts Covered
- Queue creation (`xQueueCreate`)
- Sending and receiving messages (`xQueueSend`, `xQueueReceive`)
- Producer-consumer model

## 🛠️ Hardware Required
- ESP32 Dev Board

## 🖥️ Expected Serial Output
Producer sent: 0

Consumer received: 0

Producer sent: 1

Consumer received: 1


## 📌 Notes
Queues are a safe way to transfer data between tasks without race conditions. Ideal for task decoupling and data buffering.
