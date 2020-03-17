#include <Arduino_FreeRTOS.h> 

void setup() {
  Serial.begin(115200);
  xTaskCreate(TaskWriteAnalog, "AnalogWrite", 128, NULL, 2, NULL);
  xTaskCreate(TaskWriteDigital, "DigitalWrite", 128, NULL, 1, NULL);
  vTaskStartScheduler();
}

void TaskWriteAnalog( void *pvParameters ) //priority = 1
{ (void) pvParameters;
 int i;
  for (;;){
  for(i=0;i<6;i++)
  {
    Serial.print("Analog ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(analogRead(i));
  }
  vTaskDelay(pdMS_TO_TICKS(900));
 }
}

void TaskWriteDigital( void *pvParameters ) //priority = 1
{ (void) pvParameters;
 int i;
  for (;;){
  for(i=1;i<14;i++)
  {
    Serial.print("Digitial ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(digitalRead(i));
  }vTaskDelay(pdMS_TO_TICKS(300));
 }
}

void loop(){}
