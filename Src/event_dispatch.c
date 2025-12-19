void Event_Dispatch(void)
{
    Event_t e;

    if (EventQueue_Pop(&e))
    {
        switch (e.type)
        {
            case EVENT_BUTTON_SHORT_PRESS:
                System_HandleShortPress();
                break;

            case EVENT_BUTTON_LONG_PRESS:
                System_HandleLongPress();
                break;

            default:
                break;
        }
    }
}
