#ifndef _WEATHER_H
#define _WEATHER_H

#include "Arduino.h"
#include "ArduinoJson.h"
#include "ArduinoUZlib.h"
#include "HTTPClient.h"

//定义天气类
class Weather
{
    public:
        Weather(String apiKey, String location);
        bool updateWeather();  //发送一次请求信息，获取天气数据

        int getTemp();
        int getWeather();
        int getHumidity();
    private:
        String apiKey;                  //天气API密钥
        String location;                //地点
        JsonDocument doc;   //Json容器
        JsonObject now;     //可根据返回的json信息自行定义其他天气数据
};

#endif
