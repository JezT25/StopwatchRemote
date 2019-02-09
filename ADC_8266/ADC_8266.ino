/*
   -- New project --

   This source code of graphical user interface
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.3.3 or later version
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/
     - for ANDROID 4.1.1 or later version;
     - for iOS 1.2.1 or later version;

   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings
#define REMOTEXY_WIFI_SSID "SHS-ADC Stopwatch"
#define REMOTEXY_WIFI_PASSWORD "coachbadcswimteam"
#define REMOTEXY_SERVER_PORT 6377


// RemoteXY configurate
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
{ 255, 3, 0, 0, 0, 94, 0, 8, 178, 1,
  1, 0, 17, 23, 29, 29, 107, 202, 83, 116,
  97, 114, 116, 47, 83, 116, 111, 112, 0, 1,
  0, 17, 55, 29, 29, 107, 202, 83, 112, 108,
  105, 116, 47, 82, 101, 115, 101, 116, 0, 129,
  0, 7, 7, 53, 6, 190, 65, 84, 69, 78,
  69, 79, 32, 68, 69, 32, 67, 69, 66, 85,
  0, 129, 0, 16, 13, 30, 6, 80, 83, 116,
  111, 112, 119, 97, 116, 99, 104, 0, 1, 0,
  4, 85, 12, 12, 6, 3, 77, 111, 100, 101,
  0
};

// this structure defines all the variables of your control interface
struct {

  // input variable
  uint8_t but1; // =1 if button pressed, else =0
  uint8_t but2; // =1 if button pressed, else =0
  uint8_t mode; // =1 if button pressed, else =0

  // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_MODE D1
#define PIN_BUT1 D2
#define PIN_BUT2 D3

void setup()
{
  RemoteXY_Init ();

  pinMode (PIN_BUT1, OUTPUT);
  pinMode (PIN_BUT2, OUTPUT);
  pinMode (PIN_MODE, OUTPUT);
}

void loop()  {
  RemoteXY_Handler ();

  digitalWrite(PIN_MODE, (RemoteXY.mode == 0) ? LOW : HIGH);
  digitalWrite(PIN_BUT1, (RemoteXY.but1 == 0) ? LOW : HIGH);
  digitalWrite(PIN_BUT2, (RemoteXY.but2 == 0) ? LOW : HIGH);
}
