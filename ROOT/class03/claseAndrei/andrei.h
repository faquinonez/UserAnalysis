#ifndef andrei_h
#define andrei_h


class andrei : TObject
{
   private:
     const double passwbancaria = 1239849092;
     const int asesinatos = 0;
     double height = 1.80; // m
     double weight = 60; // kg

   public:
     andrei(){};
     ~andrei(){};
     double getHeight();
     double getWeight();
     double getIMC();

};




#endif
