#include <Arduino_FreeRTOS.h>
char input = 0;

void setup() {
 Serial.begin(115200);
 xTaskCreate(TaskSerialRead, "SerialRead", 128, NULL, 1, NULL);
 xTaskCreate(TaskSerialWrite, "SerialWrite", 128, NULL, 2, NULL);
 vTaskStartScheduler();
}

void TaskSerialRead( void *pvParameters ){
 (void) pvParameters;
 for (;;){
    if(input == 'a'){
     int i;
     for(i=0;i<6;i++)
     {
       Serial.print("Analog ");
       Serial.print(i);
       Serial.print(" : ");
       Serial.println(analogRead(i));
       input = 0;
     }
   }else if (input == 'd'){
     int i;
     for(i=1;i<14;i++)
     {
       Serial.print("Digital ");
       Serial.print(i);
       Serial.print(" : ");
       Serial.println(digitalRead(i));
       input = 0;
     }
   }
 }
}

void TaskSerialWrite( void *pvParameters ){
 for(;;){
   if(Serial.available() > 0) input = Serial.read();
   vTaskDelay(pdMS_TO_TICKS(150));
 }
 
}


void loop(){}
