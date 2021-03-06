
#ifndef _LED__INIT_H
#define _LED__INIT_H


//#define vturnOff3__init()          {_SetOut0Z(pMosGall)}
#define led14   2,6
#define led13   2,5
#define led12   2,4
#define led11   3,1
#define led01234  led11,led12,led13,led14

#define led_1234_init()  _Y4( _PinitAsInRenOffOut0X, led01234 )

#define LED_off     _SetInX
#define LED_on      _SetOutX
#define LED_flash   _SetOutF

void led_1234_init_all_off(void);
void led_1234_init_test_loop(void);
void led_1_blink_once(void);
void led_1234_init_test_once_only(void);
void led_1234_init_test_once_all_by_lpm(void);
void led_1234_init_test_once(void);
void led_2_blink_once(void);
void led_12_follow_dcdc_status34(void);

//#define led_1234_init_test_by_byte_ALL   0x1F
//#define led_1234_init_test_by_byte_MSB   0x10
#define led_1234_init_test_by_byte_ALL   0x0F
#define led_1234_init_test_by_byte_MSB   0x08
void led_1234_init_test_by_byte(uint8_t ___byte);

#endif
