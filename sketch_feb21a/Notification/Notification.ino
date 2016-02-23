/*

Notification Shield Example

This example shows an application on 1Sheeld's notification shield.

By using this example, you can send notifications to your
smartphone each time you press the hardware push button
placed on pin 12.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/
#define DHT11Pin 2
#define CUSTOM_SETTINGS
#define INCLUDE_NOTIFICATION_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>
#include "DHT.h"
#include <stdlib.h>
DHT dht(DHT11Pin, DHT11);
const int BlueLed=8;
const int GreenLed=9;
const int RedLed=10;
void setup()
{
  /* Start communication. */
  OneSheeld.begin();
}

void loop()
{
    int celsius = dht.readTemperature();
     if (celsius > 20 && celsius < 23){
    digitalWrite(BlueLed,LOW);  
    digitalWrite(GreenLed,HIGH);  
    digitalWrite(RedLed,LOW);  
  }else if (celsius > 23){
    digitalWrite(BlueLed,LOW);  
    digitalWrite(GreenLed,HIGH);  
    digitalWrite(RedLed,HIGH);  
  }else{
    digitalWrite(BlueLed,LOW);
    digitalWrite(GreenLed,LOW);  
    digitalWrite(RedLed,HIGH); 
  }
    char str[10] = {0};
    char str2[10] = {"Celsius "};
    itoa(celsius,str,10);
    /* Send a notification to your phone. */
    Notification.notifyPhone(strcat(str2,str));
    /* Wait for 300 ms. */
    Serial.print(" Celsius: "); Serial.print(celsius);
asm volatile (
     "call OneSecondDelay \n\t" //delay 5 sec
     "call OneSecondDelay \n\t"
     "call OneSecondDelay \n\t"
     "call OneSecondDelay \n\t"
     "call OneSecondDelay \n\t"

     //delay
     "rjmp 4f \n\t"             //exit
 
  "OneSecondDelay: \n\t"
     "ldi r18, 0 \n\t"          //delay 1 second
     "ldi r20, 0 \n\t"
     "ldi r21, 0 \n\t"
 
  "1: ldi r24, lo8(400) \n\t"
     "ldi r25, hi8(400) \n\t"
  "2: sbiw r24, 1 \n\t"         //10x around this loop = 1ms
     "brne 2b \n\t"
     "inc r18 \n\t"
     "cpi r18, 10 \n\t"
     "brne 1b \n\t"
 
     "subi r20, 0xff \n\t"      //1000 x 1ms = 1 second
     "sbci r21, 0xff \n\t"
     "ldi r24, hi8(1000) \n\t"
     "cpi r20, lo8(1000) \n\t"
     "cpc r21, r24 \n\t"
     "breq 3f \n\t"
 
     "ldi r18, 0 \n\t"
     "rjmp 1b \n\t"
 
  "3: \n\t"
     "ret \n\t"
 
  "4: \n\t"                     //exit
  );
}
