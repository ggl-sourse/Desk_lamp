```markdown
# Desk_lamp
自适应护眼台灯控制系统

## 介绍
基于 Arduino 的开源护眼台灯，可实时监测环境光强、人体距离与姿态，自动调节亮度与色温，并支持 OLED 屏显、按键手动干预。  
硬件全开源。

## 软件架构
```
固件（Arduino C++）
├─ Desk_lamp.ino      // 主循环：光强/距离/按键调度
├─ lamp.cpp/h         // PWM 亮度
├─ oled.cpp/h         // 0.96' I²C OLED 菜单
├─ Distanse.cpp/h     // 超声波测距（坐姿提醒）
硬件
├─ PCB/               // Altium  + Gerber
