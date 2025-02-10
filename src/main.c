#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// ************************* MACROS ************************
#define SERVO_PIN 22
#define WRAP 49999
#define CLK_DIV 50
#define DELAY_MS 5000 // Tempo de espera entre mudanças de posição
#define STEP_DELAY_MS 10 // Tempo entre pequenos incrementos

volatile uint8_t STEP = 0;

const uint16_t DUTY_180 = 6000;

// Configuração do PWM
uint pwm_setup(uint8_t GPIO, uint32_t wrap, float div) {
    gpio_set_function(GPIO, GPIO_FUNC_PWM);
    uint sliceNum = pwm_gpio_to_slice_num(GPIO);
    pwm_set_clkdiv(sliceNum, div);
    pwm_set_wrap(sliceNum, wrap);
    pwm_set_enabled(sliceNum, true);
    return sliceNum;
}

int main() {
    stdio_init_all();
    sleep_ms(2000); // Aguarda inicialização

    uint slice = pwm_setup(SERVO_PIN, WRAP, CLK_DIV);

    while (true) {
        // Log de depuração
        int clk = clock_get_hz(clk_sys);
        uint32_t wrap = pwm_hw->slice[slice].top + 1;
        float freq = clk / (float)(wrap * CLK_DIV);
        printf("Frequência atual: %.2f Hz\n", freq);

        printf("SERVO: 180\n");
        pwm_set_gpio_level(SERVO_PIN, DUTY_180);
        sleep_ms(5000);


    }
}
