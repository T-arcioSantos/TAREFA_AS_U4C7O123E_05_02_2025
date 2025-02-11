# Controle de Servo Motor com PWM no Raspberry Pi Pico

Este projeto demonstra o controle de um servo motor utilizando o módulo PWM do Raspberry Pi Pico. O servo motor é movido para as posições de 0, 90 e 180 graus e, também, com um movimento suave entre as posições extremas.

---

## 📋 Funcionalidades

- **Controle Preciso do Servo Motor:**
  - Utiliza o módulo PWM (Pulse Width Modulation) do Raspberry Pi Pico para controlar o ângulo do servo motor.
  - Movimento para posições predefinidas: 0 graus, 90 graus e 180 graus.
  - Movimento suave entre 0 e 180 graus, com incrementos/decrementos de 5µs no ciclo de trabalho do PWM a cada 10ms.

- **Configuração do PWM:**
  - Frequência do PWM configurada para 50Hz (período de 20ms).
  - Divisor de clock (clkdiv) definido como 125.
  - Valor de wrap definido como 19999.

- **Ciclos de Trabalho (Duty Cycles):**
    -   0 graus: 500µs
    -   90 graus: 1470µs
    -   180 graus: 2400µs

---

## 🛠 Hardware

| Componente    | GPIO / Pino | Observações                                  |
|---------------|-------------|----------------------------------------------|
| Servo Motor   | GPIO 22     | Sinal PWM para controle do ângulo do servo. |
---

## 💻 Código

O código principal está em `TAREFA_AS_U4C7O123E_05_02_2025.c` .

**Fluxo de Execução:**

1.  **Inicialização:**
    *   Inicializa a comunicação serial (`stdio_init_all()`).
    *   Configura o pino GPIO 22 como saída PWM (`gpio_set_function()`).
    *   Obtém o "slice" PWM associado ao pino (`pwm_gpio_to_slice_num()`).
    *   Configura o divisor de clock (`pwm_set_clkdiv()`) e o valor de wrap (`pwm_set_wrap()`).
    *   Habilita o PWM (`pwm_set_enabled()`).

2.  **Posições Iniciais:**
    *   Move o servo para 180 graus (ciclo de trabalho de 2400µs) e espera 5 segundos.
    *   Move o servo para 90 graus (ciclo de trabalho de 1470µs) e espera 5 segundos.
    *   Move o servo para 0 graus (ciclo de trabalho de 500µs) e espera 5 segundos.

3.  **Movimento Suave Periódico:**
    *   Entra em um loop infinito (`while(true)`).
    *   Chama a função `movimentoSuave()` repetidamente.

4.  **Função `movimentoSuave()`:**
    *   Move o servo de 0 para 180 graus:
        *   Incrementa o ciclo de trabalho do PWM de 500µs para 2400µs em passos de 5µs.
        *   A cada incremento, espera 10ms (`sleep_ms(10)`).
    *   Move o servo de 180 para 0 graus:
        *   Decrementa o ciclo de trabalho do PWM de 2400µs para 500µs em passos de 5µs.
        *   A cada decremento, espera 10ms (`sleep_ms(10)`).

**Observação sobre a Parte 6 (LED RGB):**

Conforme o requisito 6 da tarefa, o LED RGB (GPIO 12) é *apenas observado*. Exemplos de observações e como relatá-las:

* **Fase Inicial:** Inicialmente, o LED RGB diminuiu sua intensidade em três etapas distintas. Houve um intervalo de aproximadamente 5 segundos entre cada diminuição de intensidade.

* **Fase Contínua:** Após as três diminuições iniciais, o LED RGB passou a apresentar um ciclo contínuo de aumento e diminuição de intensidade. A intensidade aumentava gradualmente até um determinado nível e, em seguida, diminuía gradualmente, repetindo esse ciclo continuamente.

---

## 📚 Bibliotecas

*   `stdio.h`: Funções padrão de entrada/saída (para comunicação serial).
*   `pico/stdlib.h`: Funções padrão do SDK do Raspberry Pi Pico.
*   `hardware/pwm.h`: Funções para controle do módulo PWM.

---

## 👥 Desenvolvedor

*   Tárcio Santos

## 🎥 Demonstração

*   https://youtu.be/mIqgC3ThXdc?si=nCx6FM29A3Yqt4Sm
