#ifndef BATTERY_H_
#define BATTERY_H_

#include "STD_Types.h"

#define BATTERY_ADC_CHANNEL          3u             
#define BATTERY_ADC_PORT             GPIO_PORTC
#define BATTERY_ADC_PIN              GPIO_PIN3

#define BATTERY_LED_PORT             GPIO_PORTD
#define BATTERY_LED_PIN              GPIO_PIN7       

#define BATTERY_R1_OHMS              20000UL         
#define BATTERY_R2_OHMS              10000UL         
#define BATTERY_VREF_MV              5000UL         
#define BATTERY_ADC_MAX              1023UL         

#define BATTERY_LOW_THRESHOLD_MV     8000UL        
#define BATTERY_SAMPLE_COUNT         16u             


#define BATTERY_LOW_ADC_THRESHOLD    546u

void BATTERY_Init             (void);
u16  BATTERY_ReadRawAdc       (void);
u16  BATTERY_ReadVoltage_mV   (void);
u8   BATTERY_IsLow            (void);
void BATTERY_UpdateLowLed     (void);


void BATTERY_LedOff           (void);
void BATTERY_LedOn            (void);

#endif /* BATTERY_H_ */
