#include "main.h"

// Define button GPIO
#define BUTTON_PORT GPIOA
#define BUTTON_PIN  GPIO_PIN_8

#define EVENT_QUEUE_SIZE 8

// Event Queue Structure
static Event_t eventQueue[EVENT_QUEUE_SIZE];
static uint8_t head = 0;
static uint8_t tail = 0;

// Push event to queue
void EventQueue_Push(Event_t event)
{
    // Implementation will be added later 
}

// Pop event from queue
uint8_t EventQueue_Pop(Event_t *event)
{
    // Implementation will be added later
    return 0;
}

// Button Task to detect button presses and generate events
void Button_Task(void)
{
    static uint8_t lastState = GPIO_PIN_SET;
    static uint32_t lastDebounceTick = 0;

    uint32_t now = HAL_GetTick();
    uint8_t currentState = HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN);
    
    // Debounce logic
    if (currentState != lastState)
    {
        lastDebounceTick = now;
    }
    // If the button state has been stable for 100 ms, consider it as a valid press
    if ((now - lastDebounceTick) > 100)
    {   
        if (currentState == GPIO_PIN_RESET && lastState == GPIO_PIN_SET)
        {
            
            Event_t event;                              // Create event
            event.type = EVENT_BUTTON_SHORT_PRESS;      // Set event type
            event.timestamp = now;                      // Set event timestamp

            EventQueue_Push(event);                     // Push event to queue
        }
    }

    lastState = currentState;
}