#ifndef GPIO_INIT_H
#define GPIO_INIT_H

void gpio_init(void);


// p1.0/vsyn3
#define vsync3_PORT_            1
#define vsync3_PIN_             0
//#define vsync3_TO_0()           { _Set0_( vsync3 ); }     // to 0
//#define vsync3_init()           { _SetOUT_(vsync3); }     // }
//#define vsync3_TO_1()           { _Set1_( vsync3 ); }     // to 1


// p1.1/vsyn4
#define vsync4_PORT_            1
#define vsync4_PIN_             1
//#define vsync4_TO_0()           { _Set0_( vsync4 ); }     // to 0
//#define vsync4_init()           { _SetOUT_(vsync4); }     // }
//#define vsync4_TO_1()           { _Set1_( vsync4 ); }     // to 1

// p1.2/vsyn5
#define vsync5_PORT_            1
#define vsync5_PIN_             2
// p1.3/vsyn6
#define vsync6_PORT_            1
#define vsync6_PIN_             3

#define vena3                   3,0
#define vena4                   2,3
#define venaALL                 2,vena3,vena4

#endif
