#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

static void gpio_setup(void) {
    // Enable GPIOA clock
    rcc_periph_clock_enable(RCC_GPIOA);

    // Set PA6 (TIM3_CH1) to alternate function output push-pull
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_2_MHZ,
                  GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO6);
}

static void timer_setup(void) {
    // Enable TIM3 clock
    rcc_periph_clock_enable(RCC_TIM3);

    // Timer base configuration
   // timer_reset(TIM3);
    timer_set_prescaler(TIM3, 72 - 1);     // 72 MHz / 72 = 1 MHz (1 µs tick)
    timer_set_period(TIM3, 20000 - 1);     // 20,000 µs = 20ms period (50 Hz, good for servos or LED dimming)

    // PWM Mode 1 on TIM3 Channel 1 (output active until compare match)
    timer_set_oc_mode(TIM3, TIM_OC1, TIM_OCM_PWM1);
    timer_enable_oc_output(TIM3, TIM_OC1);

    timer_set_oc_value(TIM3, TIM_OC1, 1500);  // 1500 µs pulse = ~7.5% duty (centered for a servo)
    timer_enable_counter(TIM3);
}

int main(void) {
    gpio_setup();
    timer_setup();

    while (1) {
        for (uint16_t duty = 1000; duty <= 2000; duty += 100) {
            timer_set_oc_value(TIM3, TIM_OC1, duty);  // Set PWM pulse width (µs)
            for (int i = 0; i < 1000000; i++) __asm__("nop");  // Simple delay
        }

        for (uint16_t duty = 2000; duty >= 1000; duty -= 100) {
            timer_set_oc_value(TIM3, TIM_OC1, duty);
            for (int i = 0; i < 1000000; i++) __asm__("nop");
        }
    }

    return 0;
}
