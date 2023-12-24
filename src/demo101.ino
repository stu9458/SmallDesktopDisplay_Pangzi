
#include "main.h"
#define  VERSION   "V101"

void setup()
{
  Serial.begin(115200);                           //初始化串口
  TFTDisplayInit();                               //初始化TFT
  
//  
//  TJpgDec.drawJpg(0,0,kaixin, sizeof(kaixin));//
//  delay(450);
//  TJpgDec.drawJpg(0,0,kaixin2, sizeof(kaixin2));//
//  delay(650);
//  TJpgDec.drawJpg(0,0,kaixin, sizeof(kaixin));//
//  delay(450);
//
//  TJpgDec.drawJpg(0,0,kaixin, sizeof(kaixin));//
//  delay(450);
// 
//
//  TJpgDec.drawJpg(0,0,chongbai, sizeof(chongbai));//
//  delay(450);
// 
//  TJpgDec.drawJpg(0,0,tiaopi, sizeof(tiaopi));//
//  delay(450);
//
//
//  TJpgDec.drawJpg(0,0,shuaku, sizeof(shuaku));//
//  delay(1000);
//  TJpgDec.drawJpg(0,0,kaixin, sizeof(kaixin));//
//  delay(2550);
//  tft.fillScreen(0x0000);
//
  
  connect_wifi();                                 //联网处理
  UDPTimeInit();                                  //初始化时间服务
  MainView();                                     //太空表主结构
//  getCityCode();                                  //通过IP地址获取城市代码
  CityWeaterShow();                           //获取天气信息
  weatherOldTime = millis();
  delay(2000);
}

void loop()
{
  if (timeStatus() != timeNotSet){ 
    if (now() != oldTime){                    //如果本次数据和上次不一样的话，刷新
      oldTime = now();
      TimeUpdateShow();
    }
  }else{
    getNtpTime();
  }
  if(millis() - weatherUpdateTime > 600000){              //10分钟更新一次天气
    weatherUpdateTime = millis();
    CityWeaterShow();
  }
  weatherShow();                                 //天气数据滚动显示
  jpgSlideShow();                                 //主界面动画
}
