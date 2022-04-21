#include "main.h"

int main01(void) {
    P1DIR |= BIT1 | BIT2;                     // P1.1 and P1.2 output

    //P1SEL1 |= BIT1 | BIT2;                    // P1.1 and P1.2 options select
    P1SEL1 |= BIT1 ;                    // P1.1 
    
    TA0CCTL1 = OUTMOD_7;                      // CCR1 reset/set
    TA0CCTL2 = OUTMOD_2;                      // CCR2 reset/set
    TA0CCR0 = 12-1;                         // PWM Period
    TA0CCR1 = 6;                            // CCR1 PWM duty cycle
    TA0CCR2 = 6;                            // CCR2 PWM duty cycle

    TA0CTL = TASSEL__SMCLK | MC__UP | TACLR;  // SMCLK, up mode, clear TAR
} // main01

int main02(void) {
    //_ForEach(_PinInitAsInOffOut0x,venaALL);
    //#define vena3                   3,0
    //#define vena4                   2,3
    P3DIR &= (~BIT0) ;
    P3REN &= (~BIT0) ;
    P3OUT &= (~BIT0) ;

    P2DIR &= (~BIT3) ;
    P2REN &= (~BIT3) ;
    P2OUT &= (~BIT3) ;

    while(1){ } // all on

    while(0){ // all off
        P3DIR |=   BIT0  ;
        P2DIR |=   BIT3  ;
    }

    while(1){
        Delay_10000ms();

        P2DIR &= (~BIT3) ;
        Delay_1000ms();
        P3DIR |=   BIT0  ;

        Delay_10000ms();

        P3DIR &= (~BIT0) ;
        Delay_1000ms();
        P2DIR |=   BIT3  ;

    }
} // main02

int main03(void) {
    //_ForEach(_PinInitAsInOffOut0x,venaALL);
    //#define vena3                   3,0
    //#define vena4                   2,3
    P3DIR |=   BIT0  ;
    P2DIR |=   BIT3  ;

    while(0){ 
        P3OUT |=   BIT0  ;
        P2OUT |=   BIT3  ;
    } // all on

    while(0){ // all off
        P3OUT &= (~BIT0) ;
        P2OUT &= (~BIT3) ;
    }

    while(1){
        Delay_100ms();

        P3OUT |=   BIT0  ;
        Delay_5ms();
        P2OUT &= (~BIT3) ;

        Delay_100ms();

        P2OUT |=   BIT3  ;
        Delay_5ms();
        P3OUT &= (~BIT0) ;

    }
} // main03

int main04(void) {
#define _SET_ON       _Set1Y
#define _SET_OFF      _Set0Y
    //_ForEach(_PinInitAsInOffOut0x,venaALL);
    //P3DIR |=   BIT0  ;
    //P2DIR |=   BIT3  ;
    _SetOutY( vena3 ) ;
    _SetOutY( vena4 ) ;
    _SetInY( vena3 ) ;
    _SetInY( vena4 ) ;

    // vena3   -> 3,0 ;          vena4  -> 2,3
    while(1){
        Delay_100ms();
        _SET_ON( vena3 ) ;  Delay_5ms();    _SET_OFF( vena4 ) ; 
        Delay_100ms();
        _SET_ON( vena4 ) ;  Delay_5ms();    _SET_OFF( vena3 ) ;

    }
} // main04


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
    if(1) main04();
    


    while(1){
        _WDT_wait_interrupt_LPM4 ;  // Enter LPM3
        __nop();                    // For debugger
    }
} // main


