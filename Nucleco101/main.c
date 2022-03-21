#include "main.h"

uint16_t _sCNT = 0 ;
void main_loop(void){
    _sCNT ++ ;
    if ( _sCNT & 0x1 ) {
        vsync3_TO_1() ;
    } else {
        vsync3_TO_0() ;
    }
    if ( _sCNT & 0x8 ) {
        vsync4_TO_1() ;
    } else {
        vsync4_TO_0() ;
    }
} // main_loop

int main(void) {
    main_init(); // _clk_init_16mhz

    while(1){
        main_loop();
    }
} // main
