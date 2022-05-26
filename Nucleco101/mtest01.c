
#include "main.h"


void main01(void) {
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

void main02(void) {
    //_ForEach(_PinInitAsInOffOut0x,venaALL);
    //#define Vena3                   3,0
    //#define Vena4                   2,3
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

void main03(void) {
    //_ForEach(_PinInitAsInOffOut0x,venaALL);
    //#define Vena3                   3,0
    //#define Vena4                   2,3
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

void main04(void) {
#define _SET4_ON      _Set1X
#define _SET4_OFF     _Set0X
    _Y1( _SetOutX, Vena3 ) ;
    _Y1( _SetOutX, Vena4 ) ;

    // Vena3   -> 3,0 ;          Vena4  -> 2,3
    while(1){
        Delay_100ms();
        _Y1( _SET4_ON, Vena3 ) ;  Delay_5ms();    _Y1( _SET4_OFF, Vena4 ) ; 
        Delay_100ms();
        _Y1( _SET4_ON, Vena4 ) ;  Delay_5ms();    _Y1( _SET4_OFF, Vena3 ) ;

    }
} // main04

void main05(void) {
#define _SET5_ON        _SetInX
#define _SET5_OFF       _SetOutX
    _Y1( _PinitAsInRenOffOut0X, Vena3 ) ;
    _Y1( _PinitAsInRenOffOut0X, Vena4 ) ;

    // Vena3   -> 3,0 ;          Vena4  -> 2,3
    while(1){
        Delay_100ms();
        _Y1( _SET5_ON, Vena3 ) ;  Delay_5ms();    _Y1( _SET5_OFF, Vena4 ) ; 
        Delay_100ms();
        _Y1( _SET5_ON, Vena4 ) ;  Delay_5ms();    _Y1( _SET5_OFF, Vena3 ) ;
    }
} // main05

void main06(void) {
#define _SET6_ON        _SetInX
#define _SET6_OFF       _SetOutX
    _Y1( _PinitAsInRenOffOut0X, Vsync3 ) ;
    _Y1( _PinitAsInRenOffOut0X, Vsync9 ) ;

    //_SET6_OFF( Vsync9 ) ;  Delay_0();    _SET6_OFF( Vsync3 ) ; // 42, 50 += 92 // 1.59A 17.96v // 600Khz , all led on
    //_SET6_ON( Vsync9 )  ;  Delay_0();    _SET6_ON( Vsync3 )  ; // 48, 45 += 93 , 1.50A 17.70v // 1.8Mhz , all led on
    while(1){
        Delay_2000ms();
        //_SET6_ON( Vsync3 ) ;  Delay_0();    _SET6_OFF( Vsync9 ) ;  // 17, 72 ; 32, 63 , 1.58A 17.92v , 600kHz, 1.8Mhz , good. NOT equal current
        Delay_2000ms();
        _Y1( _SET6_ON, Vsync9 ) ;  Delay_0();    _Y1( _SET6_OFF, Vsync3 ) ; // 60, 58 ; 44,54 , 1.58A 17.95v  1.8Mhz , 600kHz, good. equal current
        // 48-33, 50,63 ===+++ 98,99 , 1.56A, 1.58A , 17.92, 17.95v
    }
} // main06
