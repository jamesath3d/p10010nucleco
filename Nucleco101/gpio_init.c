
#include "main.h"

void gpio_init(void) {
    _gpio_init();

    // gpio_all
    _Y1( _PinitAsInRenOffOut0X, Vsync9      );
    _Y1( _PinitAsInRenOffOut0X, Vsync3      );
    _Y1( _PinitAsInRenOffOut0X, Vsync4      );
    _Y1( _PinitAsInRenOffOut0X, Vsync5      );


    _Y1( _PinitAsInRenOffOut0X, Vrt3        );
    _Y1( _PinitAsInRenOffOut0X, Vrt4        );

    _Y1( _PinitAsInRenOffOut0X, Vena3       );
    _Y1( _PinitAsInRenOffOut0X, Vena4       );
} // gpio_init

