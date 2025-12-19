#ifndef EVENT_QUEUE_H
#define EVENT_QUEUE_H

#include <stdint.h>

#define EVENT_QUEUE_SIZE 8

// Event Types Enumeration
typedef enum
{
    EVENT_NONE,
    EVENT_BUTTON_SHORT_PRESS,
    EVENT_BUTTON_LONG_PRESS
} EventType_t;

// Event Structure Definition
typedef struct
{
    EventType_t type;
    uint32_t timestamp;
} Event_t;

// Event Queue Functions
uint8_t EventQueue_Push(Event_t event);
uint8_t EventQueue_Pop(Event_t *event);

#endif