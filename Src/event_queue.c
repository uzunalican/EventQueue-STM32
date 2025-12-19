#include "event_queue.h"


static Event_t eventQueue[EVENT_QUEUE_SIZE];
// Initialize head, tail, and count
static uint8_t head = 0;
static uint8_t tail = 0;
static uint8_t count = 0;

// Push event to queue
uint8_t EventQueue_Push(Event_t event)
{
    // Check if queue is full
    if (count >= EVENT_QUEUE_SIZE)
    {
        return 0; // Queue full
    }

    // Add event to queue
    eventQueue[tail] = event;
    tail = (tail + 1) % EVENT_QUEUE_SIZE;   // Circular increment of tail
    count++;

    return 1;
}

// Pop event from queue
uint8_t EventQueue_Pop(Event_t *event)
{
    // Check if queue is empty
    if (count == 0)
    {
        return 0; // Queue empty
    }
    
    // Retrieve event from queue
    *event = eventQueue[head];
    head = (head + 1) % EVENT_QUEUE_SIZE;   // Circular increment of head
    count--;

    return 1;
}