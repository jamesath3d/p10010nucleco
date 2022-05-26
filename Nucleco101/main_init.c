
#include "main.h"

void main_init(void){
    //_WDT_disable; // _wdt_init.h
    //ClkInit( & gpio_init );    // _clk_init_16mhz // Clk16mhz // main.h
    _wdt_timer_gap_60ms_at_1Mhz_main_clk();

    gpio_init();

    led_1234_init_all_off();
    while ( 0 ) { led_1234_init_test_once_all_by_lpm(); }

    _uart_p1_5_tx_only_init();
    { uint8_t __ii = 0 ; while ( 1 ) { __ii ++ ; _uart_p1_5_tx_only_put_u8d( __ii ) ; } }

} // main_init
