#include "corruptcore.h"

Corrupt corrupt;

void setup() {

}

void loop() 
{
  corrupt.set_corrupt_pin(1,1,0);
  corrupt.write_corrupt_pin();
}
