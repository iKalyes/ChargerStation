#ifndef _WEBPAGE_H
#define _WEBPAGE_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include <WiFiManager.h>

#include <variables.h>
#include <lvgl.h>
#include <ui/ui.h>

void Webconfig();
void saveParamCallback();
void wificonfig();
void wifireset();

#endif