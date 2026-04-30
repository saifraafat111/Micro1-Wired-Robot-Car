#include "JOYSTICK.h"



void JOYSTICK_INIT(void)
{
    adc_init(AVCC, DIV_128);
    GPIO_SetPinDirection(JOYSTICK_PB_PORT, JOYSTICK_PB_PIN, GPIO_INPUT);
    GPIO_WritePin       (JOYSTICK_PB_PORT, JOYSTICK_PB_PIN, GPIO_HIGH);
}

void JOYSTICK_READ_RAW(Joystick_RawData_t *pData)
{
    if (pData == ((void*)0)) return;
    pData->x = analogRead(JOYSTICK_X_CH);
    pData->y = analogRead(JOYSTICK_Y_CH);
}

Joystick_Direction_t JOYSTICK_GET_DIR(void)
{
    Joystick_RawData_t raw;
    JOYSTICK_READ_RAW(&raw);

    u8 north = (raw.y <= JOYSTICK_LOW_THRESH ) ? 1u : 0u;
    u8 south = (raw.y >= JOYSTICK_HIGH_THRESH) ? 1u : 0u;
    u8 east  = (raw.x >= JOYSTICK_HIGH_THRESH) ? 1u : 0u;
    u8 west  = (raw.x <= JOYSTICK_LOW_THRESH ) ? 1u : 0u;

    if (north && west) return JOYSTICK_DIR_FORWARD_LEFT;
    if (north && east) return JOYSTICK_DIR_FORWARD_RIGHT;
    if (south && west) return JOYSTICK_DIR_BACKWARD_LEFT;    
    if (south && east) return JOYSTICK_DIR_BACKWARD_RIGHT;  

    if (north) return JOYSTICK_DIR_FORWARD;
    if (south) return JOYSTICK_DIR_BACKWARD;
    if (west ) return JOYSTICK_DIR_LEFT;
    if (east ) return JOYSTICK_DIR_RIGHT;

    return JOYSTICK_DIR_STOP;
}

u8 JOYSTICK_IsBtnPressed(void)
{
    return (GPIO_ReadPin(JOYSTICK_PB_PORT, JOYSTICK_PB_PIN) == GPIO_LOW) ? 1u : 0u;
}
