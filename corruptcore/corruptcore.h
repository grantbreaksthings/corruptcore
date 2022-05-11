#ifndef CORRUPTCORE_H
#define CORRUPTCORE_H

#include "Arduino.h"

typedef unsigned char byte;

//Pin connected to latch pin (ST_CP) of 74HC595
#define latch_pin 8
//Pin connected to clock pin (SH_CP) of 74HC595
#define clock_pin 12
////Pin connected to Data in (DS) of 74HC595
#define data_pin 11

class Corrupt
{
  public:
    Corrupt();
    void set_corrupt_pin(int pin, int bank, bool state);
    void write_corrupt_pin();
  private:
    byte _bank1;
    byte _bank2;
    byte _bank3;
};

#endif
