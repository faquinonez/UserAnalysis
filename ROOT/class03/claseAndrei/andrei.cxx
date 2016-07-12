#include "andrei.h"


double andrei::getHeight()
{
  return height;
}

double andrei::getWeight()
{
  return weight;
}

double andrei::getIMC()
{
  return getWeight()/(getHeight()*getHeight());
}

