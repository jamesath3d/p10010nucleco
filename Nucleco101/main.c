#include "main.h"

inline void main_loop(void){
} // main_loop

int main(void) {
    main_init(); // _clk_init_16mhz

    while(1){
        main_loop();
    }
} // main
