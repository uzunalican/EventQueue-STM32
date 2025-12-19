#include "main.h"

#define EVENT_QUEUE_SIZE 8

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
