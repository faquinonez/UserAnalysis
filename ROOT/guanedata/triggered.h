#ifndef triggered_h
#define triggered_h

#include <string>

class triggered
{
  private:


    int channel1[12];
    int channel2[12];
    int channel3[12];

    // t bitmask clockcount
    int bitmask;
    unsigned long int clockCount;

    // c 
    unsigned long int internalTriggerCounter;


};

#endif

