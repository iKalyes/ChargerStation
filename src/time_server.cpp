#include <time_server.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

lv_timer_t* NTP_timer = NULL;
lv_timer_t* NTP_Update_timer = NULL;

void time_server_init(const char* poolServerName, long timeOffset, unsigned long updateInterval)
{
    timeClient.setPoolServerName(poolServerName);
    timeClient.setTimeOffset(timeOffset * 3600);
    timeClient.setUpdateInterval(updateInterval * 3600000);
    timeClient.begin();
    NTP_timer = lv_timer_create(time_server_refresh, 100, NULL);
}

void time_server_setting(const char* poolServerName, long timeOffset, unsigned long updateInterval)
{
    timeClient.setPoolServerName(poolServerName);
    timeClient.setTimeOffset(timeOffset * 3600);
    timeClient.setUpdateInterval(updateInterval * 3600000);
}

uint8_t hour, minute, second, week;
void time_server_refresh(lv_timer_t *timer)
{
    if(WiFi.status() == WL_CONNECTED && timeClient.isTimeSet() == true)
    {
        hour = timeClient.getHours();
        minute = timeClient.getMinutes();
        second = timeClient.getSeconds();
        week = timeClient.getDay();

        lv_label_set_text_fmt(ui_Hour, "%02d", hour);
        lv_label_set_text_fmt(ui_Minute, "%02d", minute);
        lv_label_set_text_fmt(ui_Second, "%02d", second);
        
        lv_label_set_text_fmt(ui_WHour, "%02d", hour);
        lv_label_set_text_fmt(ui_WMinute, "%02d", minute);
        lv_label_set_text_fmt(ui_WSecond, "%02d", second);
    }
}

bool time_server_update_flag;
void time_server_update()
{
    if(WiFi.status() == WL_CONNECTED)
    {
        time_server_update_flag = timeClient.update();
        if(time_server_update_flag == true)
        {
            switch (week)
        {
        case 0:
            lv_label_set_text(ui_Week, "周日");
            break;
        case 1:
            lv_label_set_text(ui_Week, "周一");
            break;
        case 2:
            lv_label_set_text(ui_Week, "周二");
            break;
        case 3:
            lv_label_set_text(ui_Week, "周三");
            break;
        case 4:
            lv_label_set_text(ui_Week, "周四");
            break;
        case 5:
            lv_label_set_text(ui_Week, "周五");
            break;
        case 6:
            lv_label_set_text(ui_Week, "周六");
            break;
        }
        }
    }
}

void time_server_forceupdate()
{
    if(WiFi.status() == WL_CONNECTED && timeClient.isTimeSet() == false)
    {
        timeClient.forceUpdate();
    }
}