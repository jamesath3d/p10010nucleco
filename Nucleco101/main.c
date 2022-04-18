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

int main(void) {
    main_init(); // _clk_init_16mhz

    while(1){
        // main_loop01();
        //main_loop02();
        main_loop03();
    }
} // main
