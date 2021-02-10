# WAHG
Wearable Assisted Haptic Guidance for the Blind. Based on the LVZ Transducer based Ultrasonic Transreceiver

This is the firmware for driving Max-Sonar sensors via a PIC MCU. The project was tested and verified for use in haptics. Each max-sonar ultrasonic sensor was use to sense obstacles within a >= 1 metre range and provide a feedback to the user via cam-driven ERM motors (found in all vibrating cellular phones)

All you need is

A PIC16f877 MCU 3 Max-sonar ez0 ultrasonic sensors Maxsonars connected in a daisy chain fashion: http://www.maxbotix.com/documents/LV_Chaining_Constantly_Looping_AN_Out.pdf Motors need a driver circuit through the PIC.

The PIC was programmed on a breadboard (please check PIC16f877 data-sheet here :http://www.microchip.com/wwwproducts/en/PIC16F877) There's a difference between a PIC16f877a and PIC16f877; Point to be noted! Well, I eventually decided to put a PIC16F887 in the design as it was highly recommended for modern designs. It's more robust and reliable. I have done the PCB design in Cad-soft Eagle (v6.0 at that time). There's an LCD routine also included in the code so as to test/calibrate your max-sonar as per your needs. (see commented lines of code). The code was written from scratch during which I had 2 sleepless nights- Hard-work pays off right! I was inspired by the Atmega interrupts tutorial. (Just Google it!) Any problems feel free to voice 'em out! 
