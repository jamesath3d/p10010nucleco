
#include "main.h"

void gpio_init(void) {
} // gpio_init
void main_init(void){
    _WDT_disable; // _wdt_init.h
    ClkInit( & gpio_init );    // _clk_init_16mhz Clk16mhz // main.h

} // main_init
