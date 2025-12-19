#ifndef BUTTON_H
#define BUTTON_H

#include "event.h"

#define BUTTON_PORT GPIOA
#define BUTTON_PIN  GPIO_PIN_8

void Button_Task(void);

#endif
