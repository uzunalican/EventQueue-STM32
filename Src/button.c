#include "button.h"
#include "event_queue.h"
#include "stm32c0xx_hal.h"

// Debounce and long press thresholds
#define DEBOUNCE_MS 100
#define LONG_PRESS_MS 5000

void Button_Task(void)
{
    static uint8_t lastState = GPIO_PIN_SET;
    static uint32_t lastChangeTick = 0;
    static uint32_t pressStartTick = 0;
    static uint8_t pressed = 0;

    uint32_t now = HAL_GetTick();
    uint8_t state = HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN);
    if (state != lastState)
    {
        lastChangeTick = now;
        lastState = state;
    }

    if ((now - lastChangeTick) < DEBOUNCE_MS)
        return;

    if (state == GPIO_PIN_RESET && !pressed)
    {
        pressed = 1;
        pressStartTick = now;
    }

    if (state == GPIO_PIN_SET && pressed)
    {
        uint32_t duration = now - pressStartTick;
        pressed = 0;

        Event_t e;

        if (duration >= LONG_PRESS_MS)
            e.type = EVENT_BUTTON_LONG_PRESS;
        else
            e.type = EVENT_BUTTON_SHORT_PRESS;

        EventQueue_Push(e);
    }
}
