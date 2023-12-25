

#include <io.h>
#include <lcd.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#asm (".equ __lcd_port=0x1B")
int scan (){

    DDRD=0xf0;
    PORTD=0xff;
    PORTD.7=0;
    if (PIND.0==0) return 10;// /
    if (PIND.1==0) return 11;// *
    if (PIND.2==0) return 12;// -
    if (PIND.3==0) return 13;// +
    PORTD.7=1;
    PORTD.6=0;
    if (PIND.0==0) return 9;
    if (PIND.1==0) return 6;
    if (PIND.2==0) return 3;
    if (PIND.3==0) return 14;// = 
    

    PORTD.6=1;
    PORTD.5=0;
    if (PIND.0==0) return 8;
    if (PIND.1==0) return 5;
    if (PIND.2==0) return 2;
    if (PIND.3==0) return 0;

    PORTD.5=1;
    PORTD.4=0;
    if (PIND.0==0) return 7;
    if (PIND.1==0) return 4;
    if (PIND.2==0) return 1;
    if (PIND.3==0) return 15;// o

    return 16;// $


 }

void main(void)
{
           int num1;
 
   int key=0;
    int number1=0;
    int number2=0;
  
   int zarb=0;
   int jam=0;
  int divide=0;
  int menha=0;
  //  int final; 
    char put[10];
      char adad[2];
     //char pop[];   
   
        int k;
  lcd_init(16);
  while (1)
    {       
  
 
 
     
           
         k= scan(); 
          itoa(k,adad);  
                    if(k !=16 && k!=15 && k!=14   && k!=13    && k!=12 && k!=11 && k!=10    ){ 
       number1=number1*10;   
       num1= k;
       number1+=num1; 
             delay_ms(250);
             lcd_puts(adad);
       
       }
     
      /*   if(k !=16 && k!=15   ){ 
      number1=number1*10;   
     num1= k;
      number1+=num1; 
          delay_ms(250); }*/
       
     
         switch (k){ 
            case 14:
             lcd_putchar('=') ;
             delay_ms(2000);
               key=1;      
               
                    //lcd_clear();
               break;
        case 13: 
     lcd_putchar('+');
          
     
      
          jam=1; 
          number2=number1;   
          number1=0; 
           delay_ms(250);
            
               break;
         
        case 12:
        
    lcd_putchar('-');
    
          
             number2=number1;  
              number1=0;
                            menha=1; 
                              delay_ms(250);
               break;
 
         case 11:
     lcd_putchar('*');
    
            
             zarb=1; 
                 number2=number1;
                  number1=0;
                    delay_ms(250);
               break;
         case 10:
                lcd_putchar('/') ;
                                             
              
             divide =1; 
                 number2=number1;
                  number1=0;
          
                 delay_ms(250);
             
             break;
    
             
          }     
           
       
        if (key==1){      
          if (jam==1 ){    
        
             number1=number1+number2   ;
            jam=0;
         
               // sprintf (put,"%d" , number1);
  
       // lcd_puts(put);    
      itoa(number1,put);
              lcd_puts(put); 
         delay_ms(250);
    
        key=0;
             } 
                if ( menha ==1 ){
          number1=number2-number1   ;
             menha =0;
             itoa(number1,put);
              lcd_puts(put); 
         delay_ms(250);
          
            //    sprintf (put,"%d" , number1);
  
    //    lcd_puts(put); 
         // delay_ms(250);
    
           key=0;
             }
                if (divide==1    ){
          number1=number2/number1   ;
             divide=0;
             itoa(number1,put);
              lcd_puts(put); 
         delay_ms(250);
            
            //   sprintf (put,"%d" , number1);
  
        //lcd_puts(put); 
         // delay_ms(250); 
          key=0;
    
                      } 
                if (zarb==1 ){
             number1=number1   *   number2   ;
             zarb=0;
             itoa(number1,put);
              lcd_puts(put); 
         delay_ms(250);
           
             key=0;
        
             }   
                //  sprintf (put,"%d" , number1);
  
       // lcd_puts(put); 
         // delay_ms(250);
     
    
    
             }
           //  }      
        
      //string[ strlen(string) ] = k;
     // k= scan();
     // string[strlen(string)]= '1';
     
 
    if (k ==15){lcd_clear();
    key=0;
    number1=0;
    jam=0 ;
    menha =0;
    zarb=0;
    divide=0;}
   // if(k !=16 && k!=15){ 
   
   
  /*  if (k ==0 || k==1 || k==2 || k==3 || k==4 || k==5 || k==6 || k==7 || k==8 || k==9){
   sprintf (pop,"%d" ,k);
    lcd_puts(pop);}
    delay_ms(250); 
    
    }         */
     
 } 
 }
