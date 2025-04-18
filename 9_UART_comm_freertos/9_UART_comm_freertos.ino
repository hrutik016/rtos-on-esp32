void TxTask(void *pvParameters) {
  int count = 0;
  while (1) {
    Serial.print("TX Task: Sending count ");
    Serial.println(count++);
    vTaskDelay(2000 / portTICK_PERIOD_MS);  // Send every 2 seconds
  }
}

void RxTask(void *pvParameters) {
  while (1) {
    if (Serial.available() > 0) {
      String received = Serial.readStringUntil('\n');  // Read until newline
      Serial.print("RX Task: Received -> ");
      Serial.println(received);
    }
    vTaskDelay(10 / portTICK_PERIOD_MS);  // Small delay to avoid hogging CPU
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  xTaskCreate(TxTask, "TxTask", 1000, NULL, 1, NULL);
  xTaskCreate(RxTask, "RxTask", 1000, NULL, 1, NULL);
}

void loop() {
  // Nothing here
}