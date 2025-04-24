// Date and time functions using a DS1307 RTC connected via I2C and Wire lib
#include "RTClib.h"
#define bellPin 10
unsigned long previousMillis = 0;
unsigned long ht;
unsigned long mt;
unsigned long st;
unsigned long minhum;

RTC_DS1307 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  pinMode(bellPin,OUTPUT);
  Serial.begin(9600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    while (1) delay(10);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }

  // When time needs to be re-set on a previously configured device, the
  // following line sets the RTC to the date & time this sketch was compiled
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
   //rtc.adjust(DateTime(2024, 3, 28, 16, 35, 0));
}

void loop () {

    unsigned long currentMillis = millis();
    DateTime now = rtc.now();

     if (currentMillis - previousMillis >= 1000) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    //Serial.print("Date: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.println(now.day(), DEC);
    Serial.print(";");
   // Serial.print(" (");
    //Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    //Serial.print(") ");
   // Serial.print("Time: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

   // Serial.print(" since midnight 1/1/1970 = ");
    //Serial.print(now.unixtime());
    //Serial.print("s = ");
    //Serial.print(now.unixtime() / 86400L);
    //Serial.println("d");

    // calculate a date which is 7 days, 12 hours, 30 minutes, and 6 seconds into the future
   // DateTime future (now + TimeSpan(7,12,30,6));

    //Serial.print(" now + 7d + 12h + 30m + 6s: ");
    //Serial.print(future.year(), DEC);
    //Serial.print('/');
    //Serial.print(future.month(), DEC);
    //Serial.print('/');
    //Serial.print(future.day(), DEC);
    //Serial.print(' ');
    //Serial.print(future.hour(), DEC);
    //Serial.print(':');
    //Serial.print(future.minute(), DEC);
    //Serial.print(':');
    //Serial.print(future.second(), DEC);
    //Serial.println();

   // Serial.println();
      if (Serial.available()>0)
  {
    String val = Serial.readStringUntil('\n');
    char delimiter1 = ',';
   char delimiter2 = ';';
   char delimiter3 = ':';
   int delimiterPos1 = val.indexOf(delimiter1);
   int delimiterPos2 = val.indexOf(delimiter2);
   int delimiterPos3 = val.indexOf(delimiter3);
   String substring1 = val.substring(0, delimiterPos1);
   Serial.println(substring1);
   String substring2 = val.substring(delimiterPos1 + 1,delimiterPos2);
   Serial.println(substring2);
   String substring3 = val.substring(delimiterPos2 + 1,delimiterPos3);
   Serial.println(substring3);
   String substring4 = val.substring(delimiterPos3+1);
   Serial.println(substring4);

    ht = substring1.toInt();
    mt = substring2.toInt();
    st = substring3.toInt();
    minhum = substring4.toInt();
  }
    
     if (now.hour()==ht&&now.minute()==mt&&now.second()==st) { // Adjust time as needed
    // Ring the bell
    
    digitalWrite(bellPin, HIGH);
    delay(5000); // Bell ringing duration
    digitalWrite(bellPin, LOW);
     
  }
  }
     
}
