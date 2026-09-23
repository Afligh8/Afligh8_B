#include "stm32f4xx_hal.h"

#define LED_GREEN_PIN                          GPIO_PIN_12
#define LED_ORANGE_PIN                         GPIO_PIN_13
#define LED_RED_PIN                            GPIO_PIN_14
#define LED_BLUE_PIN                           GPIO_PIN_15
#define LED_GPIO_PORT                          GPIOD
#define LED_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOD_CLK_ENABLE()

void SystemClock_Config(void);

int main(void){

    HAL_Init();

    SystemClock_Config();

    LED_GPIO_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    HAL_GPIO_WritePin(LED_GPIO_PORT,  
                        LED_GREEN_PIN | 
                        LED_ORANGE_PIN | 
                        LED_RED_PIN | 
                        LED_BLUE_PIN, 
                        GPIO_PIN_RESET);

    GPIO_InitStruct.Pin =  LED_GREEN_PIN | LED_ORANGE_PIN | LED_RED_PIN | LED_BLUE_PIN;        
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;     // Push-Pull Output
    GPIO_InitStruct.Pull = GPIO_NOPULL;             // No pull-up/pull-down resistor
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

    while (1){

        HAL_GPIO_TogglePin(LED_GPIO_PORT,  LED_GREEN_PIN | LED_ORANGE_PIN | LED_RED_PIN | LED_BLUE_PIN);

        HAL_Delay(1000);
    }
}

//SysTick interrupt handler needed for HAL_Delay()
void SysTick_Handler(void)
{
    HAL_IncTick();
}


//brief System Clock Configuration (Default internal HSI oscillator)
//param None
//retval None
void SystemClock_Config(void) {
    // Basic HSI initialization. HAL_Init sets up a default tick, 
    // but you can expand this if you need explicit clock frequencies (e.g., 168 MHz).
}
