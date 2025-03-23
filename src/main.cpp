#include <main.h>





void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    gpio_init(); /* Initialize the GPIO */
    flash_init(); /* Initialize the flash */

    display_init(); /* Initialize the display and UI */
    ina219_init(); /* Initialize the INA219 sensor */
    adc_init(); /* Initialize the ADC input device */
    encoder_lvgl_init(); /* Initialize the encoder input device */
    lvgl_group_init(); /* Initialize the LVGL group */

    load_web_config(); /* Load the web configuration */

    delay(1000);

    Serial.print("CityCode = ");
    Serial.println(CityCode);

    Serial.print("WeaterUpdateTime = ");
    Serial.println(UpdateWeater_Time);

    Serial.print("qWeatherKey = ");
    Serial.println(qWeather_Key);

    Serial.print("TimeZone = ");
    Serial.println(TimeZone);

    Serial.print("NTPServer = ");
    Serial.println(NTPServer);
}

void loop()
{
    display_task(); /* let the GUI do its work */
}
