#ifndef PRIVATE_H
#define PRIVATE_H

#include "types.h"

#define ADCL    (*((volatile u8*)0x78))   /* نتيجة التحويل — البايت الأدنى */
#define ADCH    (*((volatile u8*)0x79))   /* نتيجة التحويل — البايت الأعلى */
#define ADCSRA  (*((volatile u8*)0x7A))   /* Control & Status A */
#define ADMUX   (*((volatile u8*)0x7C))   /* Multiplexer */


#define ADPS0   0   /* Prescaler bit 0 */
#define ADPS1   1   /* Prescaler bit 1 */
#define ADPS2   2   /* Prescaler bit 2 */
#define ADIE    3   /* Interrupt Enable */
#define ADIF    4   /* Interrupt Flag   */
#define ADATE   5   /* Auto Trigger Enable */
#define ADSC    6   /* Start Conversion */
#define ADEN    7   /* ADC Enable       */


#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define ADLAR   5   /* Left Adjust Result (0 = right-adjusted) */
#define REFS0   6   /* Voltage Reference Select 0 */
#define REFS1   7   /* Voltage Reference Select 1 */

#define setBIT(reg, pin)    ((reg) |=  (1U << (pin)))   /* خلّي البِت = 1 */
#define clearBIT(reg, pin)  ((reg) &= ~(1U << (pin)))   /* خلّي البِت = 0 */
#define readBIT(reg, pin)   (((reg) & (1U << (pin))) != 0U)  /* اقرا البِت */

#endif /* PRIVATE_H */
