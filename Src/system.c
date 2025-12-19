SystemMode_t systemMode = MODE_NORMAL;

void System_HandleShortPress(void)
{
    if (systemMode == MODE_NORMAL)
    {
        systemMode = MODE_FAULT;
        EnterFaultMode();
    }
}

void System_HandleLongPress(void)
{
    if (systemMode == MODE_FAULT)
    {
        systemMode = MODE_NORMAL;
        ExitFaultMode();
    }
}
