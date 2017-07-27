#include "definitions.h"

void init_ThinkWear(){
  for(int n = 1; n < 18; n++){
    switch(n) {
      case 1:
        SPI.transfer(WREG | CNFG1);
        SPI.transfer(0);
        SPI.transfer(CONFIG1);
        break;
      case 2:
        SPI.transfer(WREG | CNFG2);
        SPI.transfer(0);
        SPI.transfer(CONFIG2);
        break;
      case 3:
        SPI.transfer(WREG | CNFG3);
        SPI.transfer(0);
        SPI.transfer(CONFIG3);
        break;
      case 4:
        SPI.transfer(WREG | LFF);
        SPI.transfer(0);
        SPI.transfer(LOFF);
        break;
      case 5:
        SPI.transfer(WREG | CH1SET);
        SPI.transfer(0);
        SPI.transfer(CH_ON);
        break;
      case 6:
        SPI.transfer(WREG | CH2SET);
        SPI.transfer(0);
        SPI.transfer(CH_OFF);
        break;
      case 7:
        SPI.transfer(WREG | CH3SET);
        SPI.transfer(0);
        SPI.transfer(CH_OFF);
        break;
      case 8:
        SPI.transfer(WREG | CH4SET);
        SPI.transfer(0);
        SPI.transfer(CH_OFF);
        break;
      case 9:
        SPI.transfer(WREG | BIAS_SENSP);
        SPI.transfer(0);
        SPI.transfer(RSTREG);
        break;
      case 10:
        SPI.transfer(WREG | BIAS_SENSN);
        SPI.transfer(0);
        SPI.transfer(RSTREG);
        break;
      case 11:
        SPI.transfer(WREG | LOFF_SENSP);
        SPI.transfer(0);
        SPI.transfer(RSTREG);
        break;
      case 12:
        SPI.transfer(WREG | LOFF_SENSN);
        SPI.transfer(0);
        SPI.transfer(RSTREG);
        break;
      case 13:
        SPI.transfer(WREG | LOFF_FLIP);
        SPI.transfer(0);
        SPI.transfer(RSTREG);
        break;
      case 14:
        SPI.transfer(WREG | GPIO);
        SPI.transfer(0);
        SPI.transfer(RSTREG);
        break;
      case 15:
        SPI.transfer(WREG | MSC1);
        SPI.transfer(0);
        SPI.transfer(MISC1);
        break;
      case 16:
        SPI.transfer(WREG | MSC2);
        SPI.transfer(0);
        SPI.transfer(MISC2);
        break;
      case 17:
        SPI.transfer(WREG | CNFG4);
        SPI.transfer(0);
        SPI.transfer(CONFIG4);
        break;
      default:
        break;

    }//end switch
  }//end for
}//end init

