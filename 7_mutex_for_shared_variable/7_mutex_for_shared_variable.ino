#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

SemaphoreHandle_t mutex;
int sharedCounter = 0;

void CounterTask(void *pvParameters) {
  int taskNum = (int)pvParameters;

  while (1) {
    if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
      // Begin critical section
      sharedCounter++;
      Serial.print("Task ");
      Serial.print(taskNum);
      Serial.print(" incremented counter to: ");
      Serial.println(sharedCounter);
      // End critical section

      xSemaphoreGive(mutex);  // Release mutex
    }

    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Task delay
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  mutex = xSemaphoreCreateMutex();

  if (mutex != NULL) {
    // Create two tasks that share access to the same counter
    xTaskCreate(CounterTask, "Task1", 1000, (void *)1, 1, NULL);
    xTaskCreate(CounterTask, "Task2", 1000, (void *)2, 1, NULL);
  } else {
    Serial.println("Failed to create mutex.");
  }
}

void loop() {
  // Not used
}