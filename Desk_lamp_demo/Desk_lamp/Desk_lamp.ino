#include <MsTimer2.h>

/*********************************************
 *该程序建于2021年4月6日，主要实现以下功能：
 *1、灯带可以根据环境光强自主调节亮度
 *2、对周围人员测距，距离过近，并可以发出警报声
 *3、按键调节灯带亮度
 *4、OLED显示亮灯时间 
 *********************************************/
#include "Distanse.h"
#include "oled.h"
#include "lamp.h"

//结构体声明
OLED myoled;       
Distan mydistan;
Lamp mylamp;
unsigned char pwm_lamp=205;         //设置初始PWM值
unsigned int light_val=0;          //经测试正常情况下光敏电阻输出在20~1000内浮动  串电阻3.5KΩ
//设置时间变量
static unsigned char time_h=0;             //小时
static unsigned char time_f=0;             //分钟
static unsigned char time_s=0;             //秒
/**************************************************/
void key1_inter( );
void key2_inter( );
void flash_time( );
/**************************************************/
  
void setup(void)
{
  Serial.begin(9600);
  //初始化
  myoled.Init( );
  mydistan.Init( );
  mylamp.Init( );
              
  myoled.display_logo( );         //OLED显示LOGO
  
  MsTimer2::set(1000, flash);                        //0.1秒
}

void loop()
{
  if(mydistan.guang_dian( )&&(analogRead(RG)<350))  //如果光线够暗并且光电开关检测到人 
  {
   mylamp.kaideng( );                               //开灯
   MsTimer2::start();                               //定时器开
   
   while(mydistan.guang_dian( ))                    //有人使用情况下刷新一些值
   {
    mylamp.kaideng( );                              //刷新MOS驱动pwm值  按键跟光敏可以调节    
    myoled.display_ydsj(time_h,time_f,time_s);      //刷新OLED显示阅读时间 起始时间00:00；00 格式： xx小时xx分钟xx秒          
   }

 }
 else
 {
  mylamp.guandeng( );
  } 
}

/*************************中断处理函数*********************************************/
void key1_inter( )
{
  pwm_lamp+=25;
  if(pwm_lamp>=255)
  {
   pwm_lamp=255;
  }
  while(!digitalRead(KEY1));
 }

void key2_inter( )
{
  pwm_lamp-=25;
  if(pwm_lamp<=155)
  {
    pwm_lamp=155;
  }
  while(!digitalRead(KEY2));
 }
/********************************************
  定时器中断服务，根据光敏刷新lamp_pwm 计数测算时间
********************************************/
void flash(void) 
{
  int val;
  time_s++;
  if(time_s>=60)
  {
    time_f++;
    time_s-=60;
    if(time_f>=60)
    {
      time_h++;
      time_f-=60;
      }
    }
    val=analogRead(RG)*0.25-pwm_lamp;
    if((val>=25)||(val>=25))
    {
      pwm_lamp=val;
      }
}
/**************************************************************************************/
