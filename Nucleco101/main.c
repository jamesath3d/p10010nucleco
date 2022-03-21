#include "main.h"

uint16_t _sCNT = 0 ;
void main_loop(void){
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
} // main_loop

int main(void) {
    main_init(); // _clk_init_16mhz

    while(1){
        main_loop();
    }
} // main
