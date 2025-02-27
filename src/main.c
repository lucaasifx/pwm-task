#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

// ************************* MACROS ************************
// GPIO definido no pino do servomotor
    // para realizar os testes no led 
#define GPIO_PIN 22
#define WRAP 49999 // Valor de top do contador de wrap
#define CLK_DIV 50 // Divisor de clock
#define DELAY_MS 5000 // Tempo de espera entre mudanças de posição
#define STEP_DELAY_MS 10 // Tempo entre pequenos incrementos

volatile int STEP = 1250;
bool rise = false;
const uint16_t DUTY_180 = 6000;
const uint16_t DUTY_90 = 3675;
const uint16_t DUTY_0 = 1250;


// Configuração do PWM
uint pwm_setup(uint8_t gpio_num, uint32_t wrap, float div) {
    gpio_set_function(gpio_num, GPIO_FUNC_PWM);
    uint sliceNum = pwm_gpio_to_slice_num(gpio_num);
    pwm_set_clkdiv(sliceNum, div);
    pwm_set_wrap(sliceNum, wrap);
    pwm_set_enabled(sliceNum, true);
    return sliceNum;
}

void move_servo() {
    pwm_set_gpio_level(GPIO_PIN, STEP);
    // se estiver caindo
    if(!rise) {
        STEP += 12;
        if(STEP >= DUTY_180)
            rise = true;
    }
    // se estiver subindo
    else {
        STEP -= 12;
        if(STEP <= DUTY_0)
            rise = false;
    }

}

int main() {
    stdio_init_all();

    uint slice = pwm_setup(GPIO_PIN, WRAP, CLK_DIV);
    // Log de depuração
    int clk = clock_get_hz(clk_sys);
    uint32_t wrap = pwm_hw->slice[slice].top + 1;
    float freq = clk / (float)(wrap * CLK_DIV);

    // para demonstrar que a frequencia se mantém constante
    printf("Frequência atual: %.2f Hz\n", freq);

    printf("SERVO: 180\n");
    pwm_set_gpio_level(GPIO_PIN, DUTY_180);
    sleep_ms(DELAY_MS);

    printf("SERVO: 90\n");
    pwm_set_gpio_level(GPIO_PIN, DUTY_90);
    sleep_ms(DELAY_MS);

    printf("SERVO: 0\n");
    pwm_set_gpio_level(GPIO_PIN, DUTY_0);
    sleep_ms(DELAY_MS);
    while (true) {
        move_servo();
        // delay de 10ms entre as movimentações
        sleep_ms(STEP_DELAY_MS);
    }
}
