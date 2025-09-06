#include "lamp.h"
#include "oled.h"

/*******************************************
 * 函数功能：初始化相关引脚
*****************************************/
void Lamp::Init(void)
{
  pinMode(KEY1,INPUT);
  pinMode(KEY2,INPUT);
  pinMode(BUZZER,OUTPUT);
  
  noInterrupts( );                          //禁止中断
  attachInterrupt(KEY1,key1_inter,LOW);     //配置中断引脚2
  attachInterrupt(KEY2,key2_inter,LOW);     //配置中断引脚3
  interrupts( );                            //开启中断
  }

/*******************************************
 * 函数功能：蜂鸣器工作0.2S
*****************************************/
void Lamp::buzzer(void)
{
  digitalWrite(BUZZER,HIGH);
  delay(200);
  digitalWrite(BUZZER,LOW);
 }


/*******************************************
 * 函数功能：驱动LED灯带
*****************************************/
void Lamp::kaideng( )
{
  extern unsigned int pwm_lamp;         //设置初始PWM值
  analogWrite(LIGHT,pwm_lamp);
  }
  
void Lamp::guandeng( )
{
  analogWrite(LIGHT,LOW);
  }
