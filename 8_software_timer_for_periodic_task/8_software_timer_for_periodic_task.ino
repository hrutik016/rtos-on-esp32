#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"

TimerHandle_t periodicTimer;

void TimerCallback(TimerHandle_t xTimer) {
  static int counter = 0;

  Serial.print("Timer triggered! Count: ");
  Serial.println(counter);

  // Do something else here
  if (counter % 2 == 0) {
    Serial.println("Even tick – maybe check a sensor?");
  } else {
    Serial.println("Odd tick – maybe log a value.");
  }
  counter++;
}


void setup() {
  Serial.begin(115200);
  delay(1000);

  // Create a software timer with 2-second period
  periodicTimer = xTimerCreate(
    "PeriodicTimer",                   // Timer name
    pdMS_TO_TICKS(2000),              // Timer period (2000ms)
    pdTRUE,                            // Auto-reload (true = periodic)
    (void *)0,                         // Timer ID (not used)
    TimerCallback                      // Callback function
  );

  if (periodicTimer != NULL) {
    xTimerStart(periodicTimer, 0);    // Start the timer immediately
    Serial.println("Timer started.");
  } else {
    Serial.println("Failed to create timer.");
  }
}

void loop() {
  // Nothing here – FreeRTOS handles the callback via timer
}
