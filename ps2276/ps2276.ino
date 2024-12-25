#include <Arduino.h>

#include "PS2Keyboard.hpp"
#include "_PS2Kbd.h"

const int CLK_PIN55 = 18;
const int DATA_PIN55 = 19;

const int CLK_PIN2 = 22;
const int DATA_PIN2 = 23;

const int pinLed1 = 14;//8Ah mode
const int pinLed2 = 27;//NumLk
const int pinLed3 = 26;//CapsLk
const int pinLed4 = 25;//ScrLk
const int pinSw1 = 33;//force8Ah
const int pinSw2 = 32;//beepEn
const int pinSw3 = 35;
const int pinSw4 = 34;
const int pinBeep = 21;//beeper


PS2Kbd keyboard2(DATA_PIN2 ,CLK_PIN2);
esp32_ps2dev::PS2Keyboard keyboard55(CLK_PIN55, DATA_PIN55);


void setup() 
{ 
  pinMode(pinLed1,OUTPUT);
  pinMode(pinLed2,OUTPUT);
  pinMode(pinLed3,OUTPUT);
  pinMode(pinLed4,OUTPUT);
  pinMode(pinSw1,INPUT);
  pinMode(pinSw2,INPUT);
  pinMode(pinSw3,INPUT);
  pinMode(pinSw4,INPUT);
  pinMode(pinBeep,OUTPUT);
  delay(100);
  keyboard55.begin(); 
  //Serial.begin(115200);
  keyboard2.begin(); 
}



std::vector<uint8_t> keyMapper(char *scanCode)
{
  std::vector<uint8_t>sendBuf;
  sendBuf.clear();
  sendBuf.shrink_to_fit();
  sendBuf.resize(0);
  //std::vector<uint8_t>().swap(sendBuf);
  /*unsigned char ksd0E[2]={0x0e,0x00};
  unsigned char ksd54[2]={0x54,0x00};
  unsigned char ksd5B[2]={0x5b,0x00};
  unsigned char ksdE01F[3]={0xe0,0x1F,0x00};
  unsigned char ksdE027[3]={0xe0,0x27,0x00};
  unsigned char ksdE02F[3]={0xe0,0x2F,0x00};
  unsigned char ksd77[2]={0x77,0x00};
  unsigned char ksd7C[3]={0xe0,0x41,0x00};

  unsigned char ksu0E[3]={0xF0,0x0e,0x00};
  unsigned char ksu54[3]={0xF0,0x54,0x00};
  unsigned char ksu5B[3]={0xF0,0x5b,0x00};
  unsigned char ksuE01F[4]={0xe0,0xF0,0x1F,0x00};
  unsigned char ksuE027[4]={0xe0,0xF0,0x27,0x00};
  unsigned char ksuE02F[4]={0xe0,0xF0,0x2F,0x00};
  unsigned char ksu77[3]={0xF0,0x77,0x00};
  unsigned char ksu7C[4]={0xe0,0xF0,0x41,0x00};*/

  char ksd0E[2]={0x0e,0x00};
  char ksd54[2]={0x54,0x00};
  char ksd5B[2]={0x5b,0x00};
  char ksdE01F[3]={0xe0,0x1F,0x00};
  char ksdE027[3]={0xe0,0x27,0x00};
  char ksdE02F[3]={0xe0,0x2F,0x00};
  char ksd77[2]={0x77,0x00};
  char ksd7C[2]={0x7C,0x00};

  char ksu0E[3]={0xF0,0x0e,0x00};
  char ksu54[3]={0xF0,0x54,0x00};
  char ksu5B[3]={0xF0,0x5b,0x00};
  char ksuE01F[4]={0xe0,0xF0,0x1F,0x00};
  char ksuE027[4]={0xe0,0xF0,0x27,0x00};
  char ksuE02F[4]={0xe0,0xF0,0x2F,0x00};
  char ksu77[3]={0xF0,0x77,0x00};
  char ksu7C[3]={0xF0,0x7C,0x00};
  if(strcmp(scanCode,ksd0E) == 0)
  {
    sendBuf.push_back(0x62);
  }
  else if(strcmp(scanCode,ksd54) == 0)
  {
    sendBuf.push_back(0x0E);
  }
  else if(strcmp(scanCode,ksd5B) == 0)
  {
    sendBuf.push_back(0x54);
  }
  else if(strcmp(scanCode,ksdE01F) == 0)
  {
    sendBuf.push_back(0x13);
  }
  else if(strcmp(scanCode,ksdE027) == 0)
  {
    sendBuf.push_back(0x67);
  }
  else if(strcmp(scanCode,ksdE02F) == 0)
  {
    sendBuf.push_back(0x64);
  }
  else if(strcmp(scanCode,ksd77) == 0)
  {
    sendBuf.push_back(0x7C);
  }
  else if(strcmp(scanCode,ksd7C) == 0)
  {
    sendBuf.push_back(0xE0);
    sendBuf.push_back(0x41);
  }

  else if(strcmp(scanCode,ksu0E) == 0)
  {
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x62);
  }
  else if(strcmp(scanCode,ksu54) == 0)
  {
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x0E);
  }
  else if(strcmp(scanCode,ksu5B) == 0)
  {
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x54);
  }
  else if(strcmp(scanCode,ksuE01F) == 0)
  {
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x13);
  }
  else if(strcmp(scanCode,ksuE027) == 0)
  {
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x67);
  }
  else if(strcmp(scanCode,ksuE02F) == 0)
  {
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x64);
  }
  else if(strcmp(scanCode,ksu77) == 0)
  {
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x7C);
  }
  else if(strcmp(scanCode,ksu7C) == 0)
  {
    sendBuf.push_back(0xE0);
    sendBuf.push_back(0xF0);
    sendBuf.push_back(0x41);
  }
  else
  {
    for(int i=0;scanCode[i]!=0;i++)
    {
      if(/*scanCode[i]!=0xED&&scanCode[i]!=0xF1&&scanCode[i]!=0xF2&&scanCode[i]!=0xF3&&scanCode[i]!=0xF3&&scanCode[i]!=0xF4&&scanCode[i]!=0xF5&&
      scanCode[i]!=0xF6&&scanCode[i]!=0xF7&&scanCode[i]!=0xF8&&scanCode[i]!=0xF9&&scanCode[i]!=0xFA&&scanCode[i]!=0xFB&&scanCode[i]!=0xFC&&scanCode[i]!=0xFD&&*/scanCode[i]!=0xFE&&scanCode[i]!=0xFF)
        sendBuf.push_back(scanCode[i]);
    }
  }
  return sendBuf;
}





//0  1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
const char keyMapper8A_E0Make[256]=
{
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0x35,0   ,0   ,0x37,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0x3a,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0x36,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0x31,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
};
//0  1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
const char keyMapper8A_E0Break[256]=
{
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0xb7,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0xba,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0xb6,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0xb1,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
};
//0  1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
const char keyMapper8A_NonMake[256]=
{
0   ,0x70,0   ,0x6c,0x6a,0x68,0x69,0x73,0   ,0x71,0x6f,0x6d,0x6b,0x3c,0x45,0   ,
0   ,0x33,0x38,0x0e,0x41,0x18,0x24,0   ,0   ,0   ,0x01,0x0d,0x0c,0x19,0x25,0   ,//0x0e被移到下一行
0   ,0x03,0x02,0x0e,0x1a,0x27,0x26,0   ,0   ,0x34,0x04,0x0f,0x1c,0x1b,0x28,0   ,
0   ,0x06,0x05,0x11,0x10,0x1d,0x29,0   ,0   ,0   ,0x07,0x12,0x1e,0x2a,0x2b,0   ,
0   ,0x08,0x13,0x1f,0x20,0x2d,0x2c,0   ,0   ,0x09,0x0a,0x14,0x15,0x21,0x2e,0   ,
0   ,0x0a,0x16,0   ,0x22,0x2f,0   ,0   ,0x32,0x39,0x3b,0x23,0   ,0x30,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0x3e,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0x3d,0   ,0x72,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0x6e,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
};
//0  1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
const char keyMapper8A_NonBreak[256]=
{
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0xb8,0   ,0xd1,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0xb2,0xb9,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,0   ,
};

char keyMapper8A(char *scanCode)
{
  char lastTemp=0;

  //printf("%x %d     %x\n",scanCode[0],scanCode[0],keyMapper8A_NonMake[(int)scanCode[0]]);
  if(scanCode[0]==0xE0)//E0 prefix
  {
  //  printf("e0 pre\n");
    if(strlen(scanCode)==3)//E0 prefixed break
    {
  //    printf("e0 pre bre\n");
      lastTemp=keyMapper8A_E0Break[(int)scanCode[2]];
    }
    else//E0 pre make
    {
  //    printf("e0 pre mke\n");
      lastTemp=keyMapper8A_E0Make[(int)scanCode[1]];
    }
  }
  else if(scanCode[0]==0xF0)//non break
  {
  //  printf("non pre bre\n");
    lastTemp=keyMapper8A_NonBreak[(int)scanCode[1]];
  //  printf("non pre bre d\n");
  }
  else//non make
  {
  //  printf("non pre mke\n");
    lastTemp=keyMapper8A_NonMake[(int)scanCode[0]];
  //  printf("non pre mke d\n");
  }
  //printf("done\n");
  return lastTemp;
}

void loop() 
{
  char scanBuf[25]={0};
  int scanBufAddr=0;
  //uint8_t ledBuf=0;
  int i=0;
  char keyMapped8A=0;
  std::vector<uint8_t>sendBuf;

  while(1)
  {
    if (keyboard2.availableRaw()) 
    {
      if(digitalRead(pinSw2)!=0)
        digitalWrite(pinBeep,1);

      scanBuf[scanBufAddr++]=keyboard2.readRaw();
      printf("[loop] Get scancode 0x%x from PS2.",scanBuf[scanBufAddr-1]);
      if(scanBuf[scanBufAddr-1]==0xE0)
      {
        printf("Get 0xE0,needLoop.\n");
        continue;
      }
      else if(scanBuf[scanBufAddr-1]==0xF0)
      {
        printf("Get 0xF0,needLoop.\n");
        continue;
      }
      else
      {
        printf("\n");
      }
      scanBuf[scanBufAddr]=0;
      scanBufAddr=0;

      if(digitalRead(pinSw1)==0)
      {
        digitalWrite(pinLed1,1);

        keyMapped8A=keyMapper8A(scanBuf);
        if(keyMapped8A!=0)
        {
          printf("[loop] Send 0x%x to PS55\n",keyMapped8A);

          sendBuf.clear();
          sendBuf.shrink_to_fit();
          sendBuf.resize(0);

          sendBuf.push_back(keyMapped8A);
          keyboard55.send_scancode(sendBuf);
        }
      }
      else
      {
        digitalWrite(pinLed1,0);

        sendBuf=keyMapper(scanBuf);
        printf("[loop] Send");
        for(i=0;i<sendBuf.size();i++)
        {
          printf(" 0x%x",sendBuf[i]);
        }
        printf(" to PS55.\n");
        keyboard55.send_scancode(sendBuf);
      }
      delay(10);
      digitalWrite(pinBeep,0);
    }

    if(get_led_update)
    {
      //delay(500);
      /*get_led_update=0;
      ledBuf=0;
      ledBuf+=keyboard55.is_scroll_lock_led_on();
      ledBuf<<=1;
      ledBuf+=keyboard55.is_caps_lock_led_on();
      ledBuf<<=1;
      ledBuf+=keyboard55.is_num_lock_led_on();
      ledBuf<<=1;*/
      //keyboard2.setLeds(ledBuf);
      
      //keyboard2.updLEDs=1;
      //keyboard2.tryUpdateLEDs();

      get_led_update=0;
      printf("[loop] Get Num%d,Caps%d,Scroll%d.\n",keyboard55.is_num_lock_led_on(),keyboard55.is_caps_lock_led_on(),keyboard55.is_scroll_lock_led_on());

      digitalWrite(pinLed2,keyboard55.is_num_lock_led_on());
      digitalWrite(pinLed3,keyboard55.is_caps_lock_led_on());
      digitalWrite(pinLed4,keyboard55.is_scroll_lock_led_on());
    }
  }
}
