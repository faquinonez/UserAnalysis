#include "TFile.h" //clase usada para tomar el archivo .dat y crear el archivo root.
#include "TTree.h" //clase usada para crear las ramas del arbol.
#include <string>  
#include <fstream>
#include <string>

using namespace std;

int main()
{

  string a;
  string b;

  b = "electronWater.root";
  a = "electron_water.dat";

  TFile *f = new TFile(b.c_str(),"RECREATE"); //creacion de archivos .root
  TTree *T = new TTree("T","data from ascii file"); //creacion de los arboles

  Long64_t nlines = 
  T->ReadFile(a.c_str(), "kineticEnergy/d:collisionStpPwr:radiativeStpPwr:totalStpPwr:CSDARange:radiationYield:densityEffectParam"); 

  T->Write(); //escribe
  f->Close();

  return 0;
}
