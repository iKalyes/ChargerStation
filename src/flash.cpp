#include <flash.h>

Preferences flash;

void get_free_space()
{
    flash.begin("setting");
    free_space = flash.freeEntries();
    flash.end();
}

void save_setting()
{
    flash.begin("setting");
    flash.putUInt("brightness", brightness);
    flash.putUInt("sleep_time", sleep_time);
    flash.putBool("fan_switch", fan_switch);
    flash.putBool("USBC_Switch", USBC_Switch);
    flash.putBool("USBA_Switch", USBA_Switch);
    flash.end();
}

void load_setting()
{
    flash.begin("setting");
    brightness = flash.getUInt("brightness", 128);
    sleep_time = flash.getUInt("sleep_time", 600);
    fan_switch = flash.getBool("fan_switch", false);
    USBC_Switch = flash.getBool("USBC_Switch", false);
    USBA_Switch = flash.getBool("USBA_Switch", false);
    voltage0_adc = flash.getFloat("voltage0_adc", 10.85f);
    voltage1_adc = flash.getFloat("voltage1_adc", 10.85f);
    voltage2_adc = flash.getFloat("voltage2_adc", 10.85f);
    voltage3_adc = flash.getFloat("voltage3_adc", 10.85f);
    flash.end();
}

void save_USBA_setting()
{
    flash.begin("setting");
    flash.putBool("USBA_Switch", USBA_Switch);
    flash.end();
}

void save_USBC_setting()
{
    flash.begin("setting");
    flash.putBool("USBC_Switch", USBC_Switch);
    flash.end();
}

void save_adc_setting()
{
    flash.begin("setting");
    flash.putFloat("voltage0_adc", voltage0_adc);
    flash.putFloat("voltage1_adc", voltage1_adc);
    flash.putFloat("voltage2_adc", voltage2_adc);
    flash.putFloat("voltage3_adc", voltage3_adc);
    flash.end();
}

void flash_init()
{
    get_free_space(); /* Get the free space of the flash */
    load_setting(); /* Load the setting from the flash */
}