#include <ina219.h>

Adafruit_INA219 ina219;

void ina219_init()
{
  Wire.begin(SDA_PIN, SCL_PIN);
  ina219.begin();
  ina219_timer = lv_timer_create(ina219_task, 100, NULL);
}

void ina219_task(lv_timer_t *timer)
{
    voltage = ina219.getBusVoltage_V();
    current = ina219.getCurrent_mA() / 1000 * 2;
    power = ina219.getPower_mW() / 1000;

    // 电压：2位整数，2位小数
    int voltage_full = round(voltage * 100);
    int voltage_int = voltage_full / 100;
    int voltage_frac = voltage_full % 100;
    
    // 电流：2位整数，2位小数
    int current_full = round(current * 100);
    int current_int = current_full / 100;
    int current_frac = current_full % 100;
    
    // 功率：3位整数，1位小数
    int power_full = round(power * 10);
    int power_int = power_full / 10;
    int power_frac = power_full % 10;
    
    lv_label_set_text_fmt(ui_Voltage, "%02d.%02d", voltage_int, voltage_frac);
    lv_label_set_text_fmt(ui_Current, "%02d.%02d", current_int, current_frac);
    lv_label_set_text_fmt(ui_Power, "%03d.%01d", power_int, power_frac);
}
