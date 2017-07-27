#include "arduino.h"
#include <SPI.h>


/*-------------- Teensy Pins -----------------*/

#define IPIN_PWDN  (6)
#define IPIN_DRDY  (8)  
#define IPIN_RESET (9)  
#define IPIN_CS    (10) //Select        ss
#define PIN_DOUT   (11) //SPI out       mosi
#define PIN_DIN    (12) //SPI in        miso
#define PIN_SRCLK  (13) //SPI clock     sck

/*---------- System Commands ----------------*/

#define WAKEUP     0x02
#define STANDBY    0x04
#define RESET      0x06
#define START      0x08
#define STOP       0x0A

/*----------Data Read Commands --------------*/

#define RDATAC     0x10
#define SDATAC     0x11
#define RDATA      0x12

/*--------- Register Read Commands ----------*/

#define RREG       0x20
#define WREG       0x40

/*------- Register Address Commands ---------*/

#define CNFG1      0x01
#define CNFG2      0x02
#define CNFG3      0x03
#define LFF        0x04
#define CH1SET     0x05
#define CH2SET     0x06
#define CH3SET     0x07
#define CH4SET     0x08
#define BIAS_SENSP 0x0D
#define BIAS_SENSN 0x0E
#define LOFF_SENSP 0x0F
#define LOFF_SENSN 0x10
#define LOFF_FLIP  0x11
#define GPIO       0x14
#define MSC1       0x15
#define MSC2       0x16
#define CNFG4      0x17

/*--------------- Registers -----------------*/

#define CONFIG1    0x96
#define CONFIG2    0xC2
#define CONFIG3    0x7E
#define LOFF       0x00
#define CH_ON      0x52
#define CH_OFF     0x80
#define RSTREG     0x00
#define MISC1      0x20
#define MISC2      0x00
#define CONFIG4    0x00

/*-------------- Functions ------------------*/

void TW_pinInit();
void TW_regInit();
