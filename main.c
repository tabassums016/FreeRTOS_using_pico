#include <FreeRTOS.h>
#include <task.h>
#include <stdio.h>
#include "pico/stdlib.h"


void led_task()
{   
    // const uint LED_PIN = PICO_DEFAULT_LED_PIN;
     const uint LED_PIN = 13;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(100);
        gpio_put(LED_PIN, 0);
        vTaskDelay(100);
        printf("\nBlinking the led");
    }
}
void onboard_led_task()
{   
     const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    // const uint LED_PIN = 13;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    while (true) {
        gpio_put(LED_PIN, 1);
        vTaskDelay(2000);
        gpio_put(LED_PIN, 0);
        vTaskDelay(100);
        printf("\nBlinking the led");
    }
}

int main()
{
    stdio_init_all();

    xTaskCreate(led_task, "LED_Task", 256, NULL, 1, NULL);
    xTaskCreate(onboard_led_task, "onboard_LED_Task", 256, NULL, 1, NULL);
    vTaskStartScheduler();

    while(1){};

}
