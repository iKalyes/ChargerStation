#include <main.h>

void setup()
{
    Serial.begin( 115200 ); /* prepare for possible serial debug */
    display_init(); /* Initialize the display and UI */
    ina219_init(); /* Initialize the INA219 sensor */
    adc_init(); /* Initialize the ADC input device */
    gpio_init(); /* Initialize the GPIO */
    encoder_lvgl_init(); /* Initialize the encoder input device */
    lvgl_group_init(); /* Initialize the LVGL group */
}

void loop()
{
    display_task(); /* let the GUI do its work */
}
