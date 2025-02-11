#include <stdio.h> //biblioteca padrão da linguagem C
#include "pico/stdlib.h" //subconjunto central de bibliotecas do SDK Pico
#include "hardware/pwm.h" //biblioteca para controlar o hardware de PWM

#define PWM_servo_motor 22 //pino do servo motor conectado a GPIO como PWM

void movimentoSuave();

//rotina principal
int main()
{
    stdio_init_all(); 

    gpio_set_function(PWM_servo_motor, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM

    uint slice = pwm_gpio_to_slice_num(PWM_servo_motor); //obter o canal PWM da GPIO

    pwm_set_clkdiv(slice, 125); //define o divisor de clock do PWM
    pwm_set_wrap(slice, 19999); //definir o valor de wrap
    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente

    pwm_set_gpio_level(PWM_servo_motor, 2400); //definir o ciclo de trabalho (duty cycle) do pwm
    sleep_ms(5000);

    pwm_set_gpio_level(PWM_servo_motor, 1470); 
    sleep_ms(5000);

    pwm_set_gpio_level(PWM_servo_motor, 500); 
    sleep_ms(5000);
    
    //loop principal
    while (true) {
        movimentoSuave(); //chamar a função de movimento suave
    }
}

void movimentoSuave() {
    for (int i = 500; i <=2400; i += 5) {
        pwm_set_gpio_level(PWM_servo_motor, i); //definir o ciclo de trabalho (duty cycle) do pwm
        sleep_ms(10);
    }

    for (int i = 2400; i >= 500; i -= 5) {
        pwm_set_gpio_level(PWM_servo_motor, i);
        sleep_ms(10);
    }
}