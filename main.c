 #include<stdint.h>
sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD0_bit;
sbit LCD_D7 at RD7_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D4 at RD4_bit;

sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD0_bit;
sbit LCD_D7_Direction at TRISD7_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D4_Direction at TRISD4_bit;

uint16_t adc_data[2];
//char buff_1[4],buff_2[4],buff_3[4];
unsigned char channel=0;


void trigger(void)
{
PORTC.RC6=1;
delay_ms(5);
PORTC.RC6=0;
delay_ms(4);
TRISC.TRISC6=1;
}


 void main()
 {
 //unsigned int i=0;
// volatile unsigned int temp;
volatile unsigned  int r1,r2,r3; //--these will take from adc_data[0] to ~[2]whatever then in while loop r1=r1/2..
CMCON=0x07;

TRISE=0x07;
TRISB=0x00;
//PORTB=0x00;
TRISC=0x00;
TRISD=0x00;
PORTD=0x00;
ADCON1=0xC0;
ADCON0=0x81;
INTCON.GIE=1;
INTCON.PEIE=1;
PIE1.ADIE=1;
delay_us(50);
ADCON0.F2=1;

delay_ms(250);

trigger();
/*
Lcd_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
*/
  while(1){
 // Lcd_Cmd(_LCD_CLEAR);
 
 
 
  r1=adc_data[0];
  r2=adc_data[1];
  r3=adc_data[2];

  //r1=r1/2;
  if((r1>=13)&&(r1<=48))
  PORTB.F1=1;
  else {PORTB.F1=0;}
  //r2=r2/2;
  if((r2>=13)&&(r2<=48))
  PORTB.F2=1;
  else {PORTB.F2=0;}
 // r3=r3/2;
  if((r3>=13)&&(r3<=48))
  PORTB.F3=1;
  else{PORTB.F3=0;}


// temp=adc_data[i];
//value=5*temp/1024;
//i++;
//if(i=2)
// i=0;
   

/*
sprintl(buff_1,"%4u",r1);
Lcd_Out(1,1,buff_1);
sprintl(buff_2,"%4u",r2);
Lcd_Out(1,6,buff_2);
sprintl(buff_3,"%4u",r3);
Lcd_Out(1,12,buff_3);
  */


//PORTD=temp;
//PORTC=temp>>2;
        delay_ms(100);
  

  }
  }
  
  void interrupt(){
  if(PIR1.ADIF){
  PIR1.ADIF=0;

              switch(channel){
              case 0:
              adc_data[0]=(ADRESH<<8)|ADRESL;
              channel++ ;
              ADCON0=0xB1;
              break;
              
              case 1:
              adc_data[1]=(ADRESH<<8)|ADRESL;
              channel++ ;
              ADCON0=0xB9;
              break;
              
              case 2:
              adc_data[2]=(ADRESH<<8)|ADRESL;
              channel=0;
              ADCON0=0xA9;
              break;
              
              default:
              break;
              }
              delay_cyc(50);
              ADCON0.F2=1;
              }
              }