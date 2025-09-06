#ifndef __DISTANSE_H__
#define __DISTANSE_H__

#include "Arduino.h"

#define DistanceEn_Pin 5                              //超声波使能引脚 0为工作
#define Guangdian_Val 4                               //接近开关信号引脚

class Distan
{
  public:
          void Init(void);
          long getdistan(void);
          bool guang_dian(void);
  private:
          #define Distan_ON     digitalWrite(DistanceEn_Pin,LOW)
          #define Distan_OFF    digitalWrite(DistanceEn_Pin,HIGH)

};

#endif
