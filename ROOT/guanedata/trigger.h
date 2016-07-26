#ifndef trigger_h
#define trigger_h

#include <string>
#include <vector>
#include "triggered.h"

using namespace std;

class trigger
{
  private:

    // x h time date integerrep
    string time;
    string date;
    unsigned long int integerrep;

    // vector of triggered events
    vector<triggered> vectrigger;

    // x f frequency
    unsigned long int frequency;

    // r D1 temp1
    // r D2 temp2
    double temp1;
    double temp2;

    // x s <T> C <P> hPa <A> m : temperature <T>, pressure <P> and altitude (from pressure) <A>
    double temperature; // C
    double pressure; // hecto Pa
    double altitud; // m


  public:




};

#endif

