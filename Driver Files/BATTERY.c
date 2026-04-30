#include "BATTERY.h"
#include "interface.h"        
#include "GPIO_interface.h"  



void BATTERY_LedOff(void)
{
    GPIO_WritePin(BATTERY_LED_PORT, BATTERY_LED_PIN, GPIO_LOW);   
}

void BATTERY_LedOn(void)
{
    GPIO_WritePin(BATTERY_LED_PORT, BATTERY_LED_PIN, GPIO_HIGH); 
}

void BATTERY_Init(void)
{

    adc_init(AVCC, DIV_128);

    GPIO_SetPinDirection(BATTERY_ADC_PORT, BATTERY_ADC_PIN, GPIO_INPUT);
    GPIO_WritePin       (BATTERY_ADC_PORT, BATTERY_ADC_PIN, GPIO_LOW);


    GPIO_SetPinDirection(BATTERY_LED_PORT, BATTERY_LED_PIN, GPIO_OUTPUT);
    BATTERY_LedOff();
}

u16 BATTERY_ReadRawAdc(void)
{
    u8 i;
    u32 adc_sum = 0UL;

    (void)analogRead((u8)BATTERY_ADC_CHANNEL);

    for (i = 0u; i < BATTERY_SAMPLE_COUNT; i++)
    {
        adc_sum += (u32)analogRead((u8)BATTERY_ADC_CHANNEL);
    }

    return (u16)((adc_sum + ((u32)BATTERY_SAMPLE_COUNT / 2UL)) /
                 (u32)BATTERY_SAMPLE_COUNT);
}

u16 BATTERY_ReadVoltage_mV(void)
{
    u32 adc_avg = (u32)BATTERY_ReadRawAdc();


    u32 v_adc_mV  = (adc_avg * (u32)BATTERY_VREF_MV + ((u32)BATTERY_ADC_MAX / 2UL))
                    / (u32)BATTERY_ADC_MAX;

    u32 v_batt_mV = (v_adc_mV * (u32)(BATTERY_R1_OHMS + BATTERY_R2_OHMS)
                    + ((u32)BATTERY_R2_OHMS / 2UL)) / (u32)BATTERY_R2_OHMS;

    if (v_batt_mV > 65535UL)
    {
        return 65535u;
    }

    return (u16)v_batt_mV;
}

u8 BATTERY_IsLow(void)
{
    u16 adc = BATTERY_ReadRawAdc();

    return (adc <= (u16)BATTERY_LOW_ADC_THRESHOLD) ? 1u : 0u;
}

void BATTERY_UpdateLowLed(void)
{
    if (BATTERY_IsLow())
    {
        BATTERY_LedOn();
    }
    else
    {
        BATTERY_LedOff();
    }
}
