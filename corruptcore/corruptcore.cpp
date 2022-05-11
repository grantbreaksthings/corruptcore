/*
   corruptcore.h - Library for communicating with the CorruptCore hardware corrupter.
   Created by Grant , October 12, 2017.
   Released under GNU GPL V3
*/

#include "corruptcore.h"
#include "Arduino.h"

Corrupt::Corrupt()
{
  pinMode(latch_pin, OUTPUT);
  pinMode(data_pin, OUTPUT);  
  pinMode(clock_pin, OUTPUT);
  _bank1 = 0;
  _bank2 = 0;
  _bank3 = 0;
}


void Corrupt::set_corrupt_pin(int pin, int bank, bool state)
{
  pin -= 1;
  if(state)
  {
    if(bank == 1)
    {
      _bank1 = _bank1 | (1<<pin);
    }
    if(bank == 2)
    {
      _bank2 = _bank2 | (1<<pin);
    }
    if(bank == 3)
    {
      _bank3 = _bank3 | (1<<pin);
    }
    else
    {
      return;
    }
  }
  else
  {
    if(bank == 1)
    {
      _bank1 = _bank1 & ~(1<<pin);
    }
    if(bank == 2)
    {
      _bank2 = _bank2 & ~(1<<pin);
    }
    if(bank == 3)
    {
      _bank3 = _bank3 & ~(1<<pin);
    }
    else
    {
      return;
    }
  }
  
}

void Corrupt::write_corrupt_pin() {
  digitalWrite(latch_pin, LOW);
  
  shiftOut(data_pin, clock_pin, MSBFIRST, _bank3);
  shiftOut(data_pin, clock_pin, MSBFIRST, _bank2);
  shiftOut(data_pin, clock_pin, MSBFIRST, _bank1);
  
  digitalWrite(latch_pin, HIGH);

}
