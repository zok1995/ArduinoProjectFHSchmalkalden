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
    Notification.notifyPhone(str);
    /* Wait for 300 ms. */
    Serial.print(" Celsius: "); Serial.print(celsius);
    OneSheeld.delay(5000);

}
