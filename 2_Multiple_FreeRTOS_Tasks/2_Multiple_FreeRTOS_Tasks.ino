void HighPriorityTask(void *pvParameters) {
  while (1) {
    Serial.println("High Priority Task Running");
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Runs every 1 second
  }
}

void LowPriorityTask(void *pvParameters) {
  while (1) {
    Serial.println("Low Priority Task Running");
    vTaskDelay(1000 / portTICK_PERIOD_MS); // Runs every 1 second
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000); // Give serial time to init

  // Create Low Priority Task
  xTaskCreate(
    LowPriorityTask,   // Task function
    "Low Priority",    // Name
    1000,              // Stack size
    NULL,              // Parameters
    1,                 // Priority (lower)
    NULL               // Task handle
  );

  // Create High Priority Task
  xTaskCreate(
    HighPriorityTask,  // Task function
    "High Priority",   // Name
    1000,              // Stack size
    NULL,              // Parameters
    2,                 // Priority (higher)
    NULL               // Task handle
  );
}

void loop() {
  // Empty, FreeRTOS scheduler handles everything
}
