#include "Distanse.h"

/*******************************************
 * 函数功能：初始化相关引脚
*****************************************/
void Distan::Init(void)
{
  pinMode(DistanceEn_Pin,OUTPUT);
  pinMode(Guangdian_Val,INPUT);
  Distan_OFF;
  }
/*******************************************
 * 函数功能：超声波测量前方障碍物距离并打印数据
*****************************************/
long Distan::getdistan(void)
{ 
  long Distance;
  unsigned char i = 0;
  int DistanceValue[4] = {0,0,0,0};
  
  while(Serial.read()>=0);
  Distan_ON;                            //超声波使能开
  
  while(Serial.available()<=4);
  
  DistanceValue[0] = Serial.read();    //提取数据
  if( DistanceValue[0] == 0xff )       //判断是否为超声波模块数据
  {
    for(i = 1;i <= 3;i ++) {DistanceValue[i] = Serial.read();}
   }
  Distan_OFF;                          //超声波使能关
 
  Distance = DistanceValue[1] * 256 + DistanceValue[2];                   //数据处理，计算距离
  return Distance;
}
/*******************************************
 * 函数功能：读取光电开关状态
*****************************************/
bool Distan::guang_dian(void)
{
  if(digitalRead(Guangdian_Val)==0)
     return 1;
  else 
      return 0;
  }
