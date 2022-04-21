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

    
    P1DIR |= BIT1 | BIT2;                     // P1.1 and P1.2 output

    //P1SEL1 |= BIT1 | BIT2;                    // P1.1 and P1.2 options select
    P1SEL1 |= BIT1 ;                    // P1.1 
    
    TA0CCTL1 = OUTMOD_7;                      // CCR1 reset/set
    TA0CCTL2 = OUTMOD_2;                      // CCR2 reset/set
    TA0CCR0 = 12-1;                         // PWM Period
    TA0CCR1 = 6;                            // CCR1 PWM duty cycle
    TA0CCR2 = 6;                            // CCR2 PWM duty cycle

    TA0CTL = TASSEL__SMCLK | MC__UP | TACLR;  // SMCLK, up mode, clear TAR


    while(1){
        _WDT_wait_interrupt_LPM4 ;  // Enter LPM3
        __nop();                    // For debugger
    }
} // main


