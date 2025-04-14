TaskHandle_t taskAHandle = NULL;  // Global handle to Task A

void TaskA(void *pvParameters) {
  while (1) {
    Serial.println("Task A is running...");
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 sec delay
  }
}

void TaskB(void *pvParameters) {
  while (1) {
    Serial.println("Task B suspending Task A");
    vTaskSuspend(taskAHandle);  // Suspend Task A
    vTaskDelay(3000 / portTICK_PERIOD_MS);  // Wait 3 sec

    Serial.println("Task B resuming Task A");
    vTaskResume(taskAHandle);  // Resume Task A
    vTaskDelay(3000 / portTICK_PERIOD_MS);  // Wait before repeating
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);  // Allow serial to start

  xTaskCreate(
    TaskA,
    "Task A",
    1000,
    NULL,
    1,
    &taskAHandle    // Save handle to suspend/resume later
  );

  xTaskCreate(
    TaskB,
    "Task B",
    1000,
    NULL,
    2,
    NULL
  );
}

void loop() {
  // Nothing here – FreeRTOS takes over
}