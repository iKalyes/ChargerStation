#ifndef _WIFI_SERVER_H
#define _WIFI_SERVER_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiManager.h>

#include <variables.h>
#include <time_server.h>
#include <flash.h>
#include <lvgl.h>
#include <ui/ui.h>

void Webconfig();
void saveParamCallback();
void wificonfig();
void wifireset();
void wificonnect();

#endif