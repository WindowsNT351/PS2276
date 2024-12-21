#include <Arduino.h>

#include "PS2Keyboard.hpp"
#include "_PS2Kbd.h"

const int CLK_PIN55 = 19;
const int DATA_PIN55 = 18;

const int CLK_PIN2 = 22;
const int DATA_PIN2 = 23;
PS2Kbd keyboard2(DATA_PIN2 ,CLK_PIN2);
esp32_ps2dev::PS2Keyboard keyboard55(CLK_PIN55, DATA_PIN55);


void setup() 
{ 
  delay(100);
  keyboard55.begin(); 
  //Serial.begin(115200);
  keyboard2.begin(); 
}


std::vector<uint8_t>sendBuf;
std::vector<uint8_t> keyMapper(char *scanCode)
{
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

void loop() 
{
  //delay(1000);
  //keyboard55.type("PS2276 ON");

  //esp32_ps2dev::scancodes::Key key;
  char scanBuf[25]={0};
  //std::vector<uint8_t>sendBuf;
  int scanBufAddr=0;
  uint8_t ledBuf=0;
  int i=0;
  while(1)
  {
    if (keyboard2.availableRaw()) 
    {
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
      keyMapper(scanBuf);
      


      printf("[loop] Send");
      for(i=0;i<sendBuf.size();i++)
      {
        printf(" 0x%x",sendBuf[i]);
      }
      printf(" to PS55.\n");
      keyboard55.send_scancode(sendBuf);
    }

    /*if(get_led_update)
    {
      //delay(500);
      get_led_update=0;
      ledBuf=0;
      ledBuf+=keyboard55.is_scroll_lock_led_on();
      ledBuf<<=1;
      ledBuf+=keyboard55.is_caps_lock_led_on();
      ledBuf<<=1;
      ledBuf+=keyboard55.is_num_lock_led_on();
      ledBuf<<=1;
      //keyboard2.setLeds(ledBuf);
      
      //keyboard2.updLEDs=1;
      //keyboard2.tryUpdateLEDs();
      printf("[loop] Get Num%d,Caps%d,Scroll%d.Updated LEDs by 0x%x.\n",keyboard55.is_num_lock_led_on(),keyboard55.is_caps_lock_led_on(),keyboard55.is_scroll_lock_led_on(),ledBuf);
    }*/
  }
}
