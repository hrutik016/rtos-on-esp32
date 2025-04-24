#include <Wire.h>
#include "freertos/FreeRTOS.h"
#include "freertos/queue.h"

QueueHandle_t i2cDataQueue;

void I2CReaderTask(void *pvParameters) {
  int dummyTemp = 25;

  while (1) {
    // Simulate I2C read (e.g., temperature)
    dummyTemp += 1;

    Serial.print("I2C Task: Read value ");
    Serial.println(dummyTemp);

    // Send to logger via queue
    xQueueSend(i2cDataQueue, &dummyTemp, portMAX_DELAY);

    vTaskDelay(2000 / portTICK_PERIOD_MS);  // Simulate 2 sec read interval
  }
}

void LoggerTask(void *pvParameters) {
  int receivedValue;

  while (1) {
    if (xQueueReceive(i2cDataQueue, &receivedValue, portMAX_DELAY) == pdTRUE) {
      Serial.print("Logger Task: Logged value ");
      Serial.println(receivedValue);
    }
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin();  // Normally you'd also init sensor here if available

  // Create queue to transfer integer values
  i2cDataQueue = xQueueCreate(5, sizeof(int));

  if (i2cDataQueue != NULL) {
    xTaskCreate(I2CReaderTask, "I2C Task", 1000, NULL, 1, NULL);
    xTaskCreate(LoggerTask, "Logger Task", 1000, NULL, 1, NULL);
  } else {
    Serial.println("Failed to create queue.");
  }
}

void loop() {
  // Nothing here
}