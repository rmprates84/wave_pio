#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h" //biblioteca pio
#include "pio_wave.pio.h" //o arquivo de leitura pio criado após a compilação
#include "hardware/clocks.h"

#define PIN 16 //Definição do pino de saída

int main(){ //função principal
    PIO pio = pio0; //especifica o periférico pio0
    bool ok;

    //coloca a frequência de clock para 128 MHz, facilitando a divisão pelo clock
    ok = set_sys_clock_khz(128000, false);

    stdio_init_all();

    printf("iniciando a transmissão PIO");
    if (ok) printf("clock set to %ld\n", clock_get_hz(clk_sys));

    uint offset = pio_add_program(pio, &pio_wave_program); //carrega o programa
    uint sm = pio_claim_unused_sm(pio, true); 
    PIOMaxSqaureWave_program_init(pio, sm, offset, PIN, 12.80f); 

    while(1){ 

        //loop infinito
        
    }
}