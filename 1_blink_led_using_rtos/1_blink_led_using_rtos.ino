#define LED_PIN 2 
void BlinkTask(void *pvParameters) {
  pinMode(LED_PIN, OUTPUT);

  while (1) {
    digitalWrite(LED_PIN, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay 500 ms

    digitalWrite(LED_PIN, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay 500 ms
  }
}

void setup() {
  // Create FreeRTOS task
  xTaskCreate(
    BlinkTask,         // Task function
    "Blink LED Task",  // Task name
    1024,              // Stack size
    NULL,              // Parameters
    1,                 // Priority
    NULL               // Task handle
  );
}

void loop() {
  // Nothing here – everything is handled by the FreeRTOS task
}
