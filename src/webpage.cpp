#include <webpage.h>

WiFiManager wm;

//WEB配网函数
void Webconfig()
{
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP  
  
  delay(1000);
  wm.resetSettings(); // wipe settings
  
  WiFiManagerParameter  custom_weatertime("WeaterUpdateTime","Weather Update Time(Min)","10",3);
  WiFiManagerParameter  custom_citycode("CityCode","CityCode","101250101",9);
  WiFiManagerParameter  custom_qweatherkey("qWeatherKey","QWeather User Key","",32);
  WiFiManagerParameter  p_lineBreak_notext("<p></p>");

  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_citycode);
  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_weatertime);
  wm.addParameter(&p_lineBreak_notext);
  wm.addParameter(&custom_qweatherkey);
  wm.setSaveParamsCallback(saveParamCallback);

  std::vector<const char *> menu = {"wifi","restart"};
  wm.setMenu(menu);
  wm.setMinimumSignalQuality(20);  // set min RSSI (percentage) to show in scans, null = 8%

  bool res;
   res = wm.autoConnect("CharingStation"); // anonymous ap
  
  while(!res);
}

String getParam(String name){
    //read parameter from server, for customhmtl input
    String value;
    if(wm.server->hasArg(name)) {
      value = wm.server->arg(name);
    }
    return value;
  }

void saveParamCallback(){
    
    Serial.println("[CALLBACK] saveParamCallback fired");
    // Serial.println("PARAM CityCode = " + getParam("CityCode"));
    // Serial.println("PARAM WeaterUpdateTime = " + getParam("WeaterUpdateTime"));
    
    //将从页面中获取的数据保存
    UpdateWeater_Time = getParam("WeaterUpdateTime").toInt();
    CityCode =  getParam("CityCode").toInt();
    qWeather_Key = getParam("qWeatherKey");
  
    //对获取的数据进行处理
    //城市代码
    Serial.print("CityCode = ");
    Serial.println(CityCode);
    if(CityCode>=101000000 && CityCode<=102000000 || CityCode == 0)
    {

    }
    Serial.print("WeaterUpdateTime = ");
    Serial.println(UpdateWeater_Time);

    Serial.print("qWeatherKey = ");
    Serial.println(qWeather_Key);
  }

void wificonfig()
{
    while(WiFi.status() != WL_CONNECTED)
    {
        Webconfig();
    }
    if(WiFi.status() == WL_CONNECTED)
    {
        Serial.print("SSID:");
        Serial.println(WiFi.SSID().c_str());
        Serial.print("PSW:");
        Serial.println(WiFi.psk().c_str());
        Serial.print("IP:");
        Serial.println(WiFi.localIP());
        Serial.print("RSSI:");
        Serial.println(WiFi.RSSI());

        lv_label_set_text(ui_WIFIStatus, "Connected");
        lv_label_set_text(ui_SSID, WiFi.SSID().c_str());
        lv_label_set_text(ui_IPADDR, WiFi.localIP().toString().c_str());
        lv_label_set_text(ui_RSSI, String(WiFi.RSSI()).c_str());

        lv_img_set_src(ui_ImageWiFi, &ui_img_593743026);
    }
}

void wifireset()
{
  wm.resetSettings();
  ESP.restart();
}