#include "DHT.h"

#include <stdlib.h>
#define DHT11Pin 2
#define CUSTOM_SETTINGS
#define INCLUDE_NOTIFICATION_SHIELD
//#define INCLUDE_DATA_LOGGER_SHIELD
//#define INCLUDE_MIC_SHIELD

#include <OneSheeld.h>
DHT dht(DHT11Pin, DHT11);
const int BlueLed=10;
const int GreenLed=9;
const int RedLed=8;

void setup()
{
   OneSheeld.begin();
 //  Logger.stop();
pinMode(BlueLed,OUTPUT);
pinMode(GreenLed,OUTPUT);
pinMode(RedLed,OUTPUT);
Serial.begin(9600);
}

void loop()
{
//    Logger.stop();
  // get humidity
  float humidity = dht.readHumidity();
  // get temperature as C
  int celsius = dht.readTemperature();
  // get temperature as F
  float fahrenheit = dht.readTemperature(true);
  char str[10] = {0};
  itoa(celsius,str,10);
  Notification.notifyPhone("1213123123");
/*     Logger.start("Mic values");
     Logger.add("Decibles",celsius);
     Logger.log(); 
    OneSheeld.delay(5000);
 if (celsius >= 20.0){
    digitalWrite(BlueLed,LOW);  
    digitalWrite(GreenLed,HIGH);  
    digitalWrite(RedLed,LOW);  
  }else if (celsius > 25.0){
    digitalWrite(BlueLed,LOW);  
    digitalWrite(GreenLed,HIGH);  
    digitalWrite(RedLed,HIGH);  
  }else{
    digitalWrite(BlueLed,LOW);
    digitalWrite(GreenLed,LOW);  
    digitalWrite(RedLed,HIGH); 
  }
  */
 

// wait 2 seconds between readings

  
  // print results
  Serial.print("Humidity: "); Serial.print(humidity);
  Serial.print(" Celsius: "); Serial.print(celsius);
  Serial.print(" Fahrenheit: "); Serial.println(fahrenheit);
}
