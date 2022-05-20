#include "main.h"


int main(void) {
    main_init(); // _clk_init_16mhz

    while(0){
        _WDT_wait_interrupt_LPM4 ;  // Enter LPM3
        __nop();                    // For debugger
    }

    //_gpio_mclk_p13  ;
    //_gpio_smclk_p17 ;
    //_gpio_aclk_p22  ;

    if(0) main01();
    if(0) main02();
    if(0) main03();
    if(0) main04();
    if(0) main05();
    if(1) main06();



    while(1){
        _WDT_wait_interrupt_LPM4 ;  // Enter LPM3
        __nop();                    // For debugger
    }
} // main


