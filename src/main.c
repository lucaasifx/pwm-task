#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// ************************* LIBS **************************



// ************************* MACROS ************************
#define SERVO_PIN 22


int main() {
    stdio_init_all();


    while(true) {


        // para evitar que o loop seja executado muito rapidamente
        sleep_ms(100);
    }
}