TaskHandle_t receiverTaskHandle = NULL;

void SenderTask(void *pvParameters) {
  while (1) {
    vTaskDelay(2000 / portTICK_PERIOD_MS);  // Every 2 seconds
    Serial.println("Sender Task: Sending notification...");

    xTaskNotifyGive(receiverTaskHandle);  // Signal the receiver
  }
}

void ReceiverTask(void *pvParameters) {
  while (1) {
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);  // Wait for notification
    Serial.println("Receiver Task: Got notification!");
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  xTaskCreate(ReceiverTask, "Receiver", 1000, NULL, 1, &receiverTaskHandle);
  xTaskCreate(SenderTask, "Sender", 1000, NULL, 1, NULL);
}

void loop() {
  // Nothing here
}