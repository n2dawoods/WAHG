


void InitADC(void)
{       CMCON=0x07;
        ADCON1  = 0xC0;             // Make PORTA and PORTE analog input pins all 0000
                                    // Also, Vref+ = 5v and Vref- = GND

        TRISE   = 0x07;                 // Make RE0, RE1 and RE2 input
        ADCON0  = 0x81;                 // Turn on the A/D Converter
}



 

unsigned int GetADCValue(unsigned char Channel)
{
        
        ADCON0 &= 0xc7;         // Clear Channel selection bits
        ADCON0 = 0x81|(Channel<<3); // Select channel pin as ADC input

/*switch(Channel)
{
case 5:
ADCON0 = 0b10110111;
break;
case 6:
ADCON0 = 0b10110011;
break;
case 7:
ADCON0 = 0b10111011;
default:;
} */
    delay_us(50);         // Time for Acqusition capacitor to charge up and show correct value
                                                        
    GO_DONE_bit  = 1;                    // Enable Go/Done whatever ....

        while(GO_DONE_bit);        // Wait for conversion completion

        return ((ADRESH<<8)|ADRESL);   // Return 10 bit ADC value
}