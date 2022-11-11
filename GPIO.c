#include "lib/include.h"
extern void Configurar_GPIO(void)
{
SYSCTL->RCGCGPIO |=(1<<5);// 1) activate clock for Port F
  GPIOF->LOCK = 0x4C4F434B;// 2) unlock GPIO Port F
  GPIOF->CR = (1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);
  GPIOF->AMSEL = 0x00; //3) disable analog on PF
  GPIOF->PCTL = 0x00000000; // 4) PCTL GPIO on PF4-0
  GPIOF->DIR = 0X0E; // ENTRADAS Y SALIDAS PF4,PF0 in, PF3-1 out //O Va a ser entrada, 1 salida
  GPIOF->AFSEL = 0X00; // 6) disable alt funct on PF7-0 deshabilitar funciones alternativas, es decir qu eno funcione como pwm etc
  GPIOF->PUR = 0x11;  // enable pull-up on PF0 and PF4 (en 1) 
  GPIOF->DEN = (1<<4)|(1<<3)|(1<<2)|(1<<1)|(1<<0);  // 7) enable digital I/O on PF4-0
  //SYSCTL->RCGC2 |= 0x00000020;
 // SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F     
 }
 extern void Delay(void)
 {
        unsigned long volatile time;
        time = 1600000;
        while(time)
        {
            time--;
        }
 }