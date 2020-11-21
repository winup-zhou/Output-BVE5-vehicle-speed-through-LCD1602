String comdata = "";
int numdata[6] = {0}, mark = 0;

char trainspeed = 0;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200,SERIAL_8N1);
  lcd.init();  
  lcd.backlight();  
}

void loop() {
        int j = 0;
     
      //不断循环检测串口缓存，一个个读入字符串，
      while (Serial.available() > 0)
      {
      //读入之后将字符串，串接到comdata上面。
        comdata += char(Serial.read());
          //延时一会，让串口缓存准备好下一个数字，不延时会导致数据丢失，
        delay(2);
        //标记串口读过数据，如果没有数据的话，直接不执行这个while了。
        mark = 1;
      }
     
      if(mark == 1)  //如果接收到数据则执行comdata分析操作，否则什么都不做。
      {
    //以串口读取字符串长度循环，
        for(int i = 0; i < comdata.length() ; i++)
        {
        //逐个分析comdata[i]字符串的文字，如果碰到文字是分隔符（这里选择/分割）则将结果数组位置下移一位
        //即比如11,22,33,55开始的11记到numdata[0];碰到逗号就j等于1了，
        //再转换就转换到numdata[1];再碰到逗号就记到numdata[2];以此类推，直到字符串结束
          if(comdata[i] == '/')
          {
            j++;
          }
          else
          {
            numdata[j] = numdata[j] * 10 + (comdata[i] - '0');
          }
        }
        comdata = String("");
      }
  // put your main code here, to run repeatedly:    
        for(int i = 0; i < 6; i++)
        {
        lcd.setCursor(10,0);
        lcd.print(numdata[i]);
        lcd.setCursor(0,0);
        lcd.print("Speed:");
        numdata[i] = 0;
        }
        //输出之后必须将读到数据的mark置0，不置0下次循环就不能使用了。
        mark = 0;
}

