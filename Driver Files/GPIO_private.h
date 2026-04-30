#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#include "STD_Types.h"


#define PINB    (*((volatile u8*)0x23))   /* قراءة PORTB */
#define DDRB    (*((volatile u8*)0x24))   /* اتجاه PORTB */
#define PORTB   (*((volatile u8*)0x25))   /* كتابة PORTB */

#define PINC    (*((volatile u8*)0x26))   /* قراءة PORTC */
#define DDRC    (*((volatile u8*)0x27))   /* اتجاه PORTC */
#define PORTC   (*((volatile u8*)0x28))   /* كتابة PORTC */

#define PIND    (*((volatile u8*)0x29))   /* قراءة PORTD */
#define DDRD    (*((volatile u8*)0x2A))   /* اتجاه PORTD */
#define PORTD   (*((volatile u8*)0x2B))   /* كتابة PORTD */

#endif /* GPIO_PRIVATE_H_ */
