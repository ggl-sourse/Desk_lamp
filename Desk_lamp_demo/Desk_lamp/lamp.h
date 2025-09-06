
#include "Arduino.h"

#ifndef __LAMP_H__
#define __LAMP_H__

#define KEY1      2
#define KEY2      3
#define BUZZER    17

#define RG       14                       //读光线强度引脚
#define LIGHT     6                       //调PWM引脚

//按键相关函数声明
class Lamp
{
  public:
          void Init(void);
          void buzzer(void);
          void kaideng( );
          void guandeng( );
          #define lamp_on     analogWrite(LIGHT,pwm_lamp)
          #define lamp_off    analogWrite(LIGHT,0)

          //#define KEY1_Val    digitalRead(KEY1)
          //#define KEY2_Val    digitalRead(KEY2)
};

void key1_inter( );                      //中断服务函数1
void key2_inter( );                      //中断服务函数2
     
#endif
