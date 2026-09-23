
#ifndef LPT
#define LPT
#include<Arduino.h>
#define printf Serial.println


int value;
bool useD1 = false;
void initLPT(){
  Serial.begin(9600);
  DDRC = 0b11111111;
  DDRD=0b11111111;
  DDRB =0b00000000;
}
// template <typename T>
// void printf(T sms){ 
  
//   Serial.println(sms);
// }
// // void printf(char sms[]){ 
// //   s
// //   Serial.println(sms);
// // }

void outportb(int addr , byte code)
{
  if(addr == int(0x378)){
    if(( (code) & (0x01) ) == 0x01){
      PORTC|=0x10;
      useD1 = true;
      PORTD = (code & ~(0x01));
    }else {
      PORTD = code;
      PORTC &= ~(0x10); 
      useD1 = false;
    }
  }else if(addr == int(0x37A))
  {
    PORTC = useD1?code|0x10 : code ;
    
  }
}

byte inportb(int addr){
  if(addr == (int)0x379)
  {
     return PINB - 0x40;
  }else
  {
    return 0;
  }
 
}

#endif
