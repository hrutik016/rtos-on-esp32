QueueHandle_t dataQueue;

void ProducerTask(void *pvParameters) {
  int count = 0;
  while (1) {
    Serial.print("Producer sent: ");
    Serial.println(count);
    xQueueSend(dataQueue, &count, portMAX_DELAY);  // Send to queue
    count++;
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Every 1 second
  }
}

void ConsumerTask(void *pvParameters) {
  int receivedVal;
  while (1) {
    if (xQueueReceive(dataQueue, &receivedVal, portMAX_DELAY) == pdPASS) {
      Serial.print("Consumer received: ");
      Serial.println(receivedVal);
    }
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  // Create a queue capable of holding 5 integers
  dataQueue = xQueueCreate(5, sizeof(int));

  if (dataQueue != NULL) {
    xTaskCreate(ProducerTask, "Producer", 1000, NULL, 1, NULL);
    xTaskCreate(ConsumerTask, "Consumer", 1000, NULL, 1, NULL);
  } else {
    Serial.println("Queue creation failed!");
  }
}

void loop() {
  // Not used
}
