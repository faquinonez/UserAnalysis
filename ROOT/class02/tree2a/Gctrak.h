#ifndef Gctrak_h
#define Gctrak_h

#include "TObject.h"

class Gctrak : public TObject {
public:
  Float_t  vect[7]; 
  Float_t  getot; 
  Float_t  gekin; 
  Float_t  vout[7];   //! not persistent
  Int_t    nmec; 
  Int_t   *lmec;      //[nmec]
  Int_t   *namec;     //[nmec]
  Int_t    nstep;     //! not persistent
  Int_t    pid; 
  Float_t  destep; 
  Float_t  destel;    //! not persistent
  Float_t  safety;    //! not persistent
  Float_t  sleng;     //! not persistent
  Float_t  step;      //! not persistent
  Float_t  snext;     //! not persistent
  Float_t  sfield;    //! not persistent 
  Float_t  tofg;      //! not persistent
  Float_t  gekrat;    //! not persistent 
  Float_t  upwght;    //! not persistent 
  
  Gctrak() {lmec=0; namec=0;}
  
  ClassDef(Gctrak,1)
}; 


#endif
