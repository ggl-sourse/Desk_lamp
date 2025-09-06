
#include "oled.h"

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 64, &Wire);


/*****************************************************
函数功能：OLED初始化设置
 *******************************************************/
void OLED::Init(void)
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  }
  
/********************************************************
 * 函数功能：OLED显示字符
 *******************************************************/
void OLED::display_char(char _text,unsigned int x,unsigned int y){
  display.clearDisplay();                                               //缓存区置零
  display.display();
  display.setTextSize(1);                                                //字体大小
  display.setTextColor(SSD1306_WHITE);                                   //字体颜色
  display.setCursor(x,y);                                                //起始坐标
  display.print(_text);
  //display.print('b');
  //display.print('c');
  display.display();                                                     //上传数据
}

/********************************************************
 * 函数功能：OLED显示阅读时间
 *******************************************************/
void OLED::display_ydsj(unsigned char time_h,unsigned char time_f,unsigned char time_s ){

  display.clearDisplay();                                               //缓存区置零
  display.display();
  display.setTextSize(2);                                                //字体大小
  display.setTextColor(SSD1306_WHITE);                                   //字体颜色
  
  display.drawBitmap(x_wz+0,0,yue,16,16, 1);
  display.drawBitmap(x_wz+16,0,du,16,16, 1);
  display.drawBitmap(x_wz+32,0,shi,16,16, 1);
  display.drawBitmap(x_wz+48,0,jian,16,16, 1);
  
  display.setCursor(16,y_wz);                                                //起始坐标
  display.print(time_h/10);
  display.print(time_h%10);
  display.print(':');  
  display.print(time_f/10);
  display.print(time_f%10);
  display.print(':');
  display.print(time_s/10);
  display.print(time_s%10);
  display.display();                                                     //上传数据
}  

/********************************************************
 * 函数功能：OLED显示LOGO
 *******************************************************/
void OLED::display_logo(void){
  display.clearDisplay();                                               //缓存区置零
  display.display();
  //display.setTextSize(5);                                                //字体大小
  display.setTextColor(SSD1306_WHITE);                                   //字体颜色
  //display.setCursor(0,0);                                                //起始坐标
  display.drawBitmap(32,0,logo, 64, 64, 1);
  display.display();                                                     //上传数据
} 
