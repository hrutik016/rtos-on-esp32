#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

SemaphoreHandle_t resourceSemaphore;

void AccessResourceTask(void *pvParameters) {
  int taskNum = (int)pvParameters;

  while (1) {
    if (xSemaphoreTake(resourceSemaphore, portMAX_DELAY) == pdTRUE) {
      Serial.print("Task ");
      Serial.print(taskNum);
      Serial.println(" accessing resource...");

      vTaskDelay(2000 / portTICK_PERIOD_MS);  // Simulate usage time

      Serial.print("Task ");
      Serial.print(taskNum);
      Serial.println(" releasing resource.");

      xSemaphoreGive(resourceSemaphore);  // Release the resource
      vTaskDelay(5000 / portTICK_PERIOD_MS);  // Wait before retrying
    }
  }
}

void setup() {
  Serial.begin(9600);
  delay(2000);

  // Create counting semaphore with 2 available resources
  resourceSemaphore = xSemaphoreCreateCounting(2, 2);  // max count, initial count

  if (resourceSemaphore != NULL) {
    for (int i = 1; i <= 4; i++) {
      xTaskCreate(
        AccessResourceTask,
        ("Task" + String(i)).c_str(),
        3000,
        (void *)i,
        1,
        NULL
      );
    }
  } else {
    Serial.println("Failed to create counting semaphore.");
  }
}

void loop() {
  // Not used
}
