#ifndef MAIN_H
#define MAIN_H

// _clk_init_16mhz
//#define Clk16384
//#define Clk8mhz   
//#define Clk1mhz   
#define Clk16mhz    

#include "_include_all.h"

#include "wdt_init.h"
#include "gpio_init.h"
#include "main_init.h"

#include "led__init.h"

#include "interupt_timer.h"
#include "interupt_wdt.h"


#include "mtest01.h"
#include "mtest02.h"
#include "mtest03.h"


#endif
