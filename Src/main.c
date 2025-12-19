#include "main.h"
#include "event_queue.h"


void SystemClock_Config(void);
static void MX_GPIO_Init(void);


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


int main(void)
{

    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();

    Event_t event;

    while (1)
    {
        Button_Task();

        if (EventQueue_Pop(&event))
        {
            // Event dispatch 
            switch (event.type)
            {
                case EVENT_BUTTON_SHORT_PRESS:
                    
                    break;

                case EVENT_BUTTON_LONG_PRESS:
                    
                    break;

                default:
                    break;
            }
        }
    }
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_LSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

// Prototype for GPIO Initialization
/*static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
    uint16_t pinMask = 0;                       // Initialize pin mask
    for (uint8_t i = 0; i < LED_COUNT; i++)     // Iterate through LEDs
        {
            pinMask |= leds[i].pin;                 // Add each LED pin to the mask
        }
    GPIO_InitStruct.Pin = pinMask;              // Set pin mask for all LEDs
    

    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(BUTTON_PORT, &GPIO_InitStruct);

}
*/

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */