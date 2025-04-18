#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"

#define BUTTON_PIN  0   // You can change this to GPIO where your button is connected
#define DEBOUNCE_DELAY 200

SemaphoreHandle_t binarySemaphore;
volatile unsigned long lastInterruptTime = 0;

void IRAM_ATTR handleButtonInterrupt() {
  unsigned long currentTime = millis();
  if ((currentTime - lastInterruptTime) > DEBOUNCE_DELAY) {
    xSemaphoreGiveFromISR(binarySemaphore, NULL);  // Give semaphore from ISR
    lastInterruptTime = currentTime;
  }
}

void ButtonTask(void *pvParameters) {
  while (1) {
    if (xSemaphoreTake(binarySemaphore, portMAX_DELAY) == pdTRUE) {
      Serial.println("Button Press Detected!");
    }
  }
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Button connected between GPIO and GND

  binarySemaphore = xSemaphoreCreateBinary();

  if (binarySemaphore != NULL) {
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonInterrupt, FALLING);
    xTaskCreate(ButtonTask, "Button Task", 1000, NULL, 1, NULL);
  } else {
    Serial.println("Failed to create semaphore.");
  }
}

void loop() {
  // FreeRTOS handles everything
}
