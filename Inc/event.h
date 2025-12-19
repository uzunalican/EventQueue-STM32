typedef enum
{
    EVENT_NONE,
    EVENT_BUTTON_SHORT_PRESS,
    EVENT_BUTTON_LONG_PRESS
} EventType_t;

typedef struct
{
    EventType_t type;
} Event_t;