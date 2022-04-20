#include "main.h"

/*
uint16_t _sCNT = 0 ;
void main_loop01(void){
    _sCNT ++ ;
    if ( _sCNT & 0x1 ) {
        _Set1_(vsync3);
    } else {
        _Set0_(vsync3);
    }
    if ( _sCNT & 0x2 ) {
        _Set1_(vsync4);
    } else {
        _Set0_(vsync4);
    }
} // main_loop01

inline void main_loop02(void){
    _Set1_(vsync4);

    _Set1_(vsync3);
    _Set0_(vsync3);
    //_Set1_(vsync3);
    //_Set0_(vsync3);

    _Set0_(vsync4);

    _Set1_(vsync3);
    _Set0_(vsync3);
    //_Set1_(vsync3);
    //_Set0_(vsync3);
} // main_loop02
*/

inline void main_loop03(void){
    _Set1_(vsync4);
    _Set0_(vsync3);
    __nop();
    __nop();
    _Set0_(vsync4);
    _Set1_(vsync3);
    //_Set1_(vsync3);
    //_Set0_(vsync3);
} // main_loop03

uint8_t rc01 ;
uint8_t rc02 ;

int mainX1(void) {
    main_init(); // _clk_init_16mhz


    if ( 1 ) {
        _Set0_(vsync3);
        _Set1_(vsync4);
        _Set0_(vsync5);
        _Set1_(vsync6);
        rc01 = P1OUT;
        _Set1_(vsync3);
        _Set0_(vsync4);
        _Set1_(vsync5);
        _Set0_(vsync6);
        rc02 = P1OUT;
    }

    while(1){
        // main_loop01();
        //main_loop02();
        //main_loop03();
        //_Set0_(vsync3); _Set1_(vsync3);

        //Delay_1000ms();
        if (1){
            P1OUT=rc01;
            __delay_cycles(1);
            P1OUT=rc02;
        }
    }
} // mainX1
int main(void) {
        P1DIR |= BIT3 ; P1SEL1 |= BIT3 ; P1SEL0 &= ~BIT3 ; // dir->1, selx->10 : link mclk  to p1.3, for oscilloscope debuging
        P1DIR |= BIT7 ; P1SEL1 |= BIT7 ; P1SEL0 &= ~BIT7 ; // dir->1, selx->10 : link smclk to p1.7, for oscilloscope debuging
        while(1){
        }
} // main
