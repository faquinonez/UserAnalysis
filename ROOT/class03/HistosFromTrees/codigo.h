//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May  1 17:09:18 2012 by ROOT version 5.28/00g
// from TTree T/data from ascii file
// found on file: SierraNegra200811120500.root
//////////////////////////////////////////////////////////

#ifndef codigo_h
#define codigo_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1I.h> //crea histogramas recibiendo datos enteros
#include <TH1F.h> //crea histogramas recibiendo datos flotantes
#include <TH1D.h> //crea histogramas recibiendo datos double
#include <string>

using namespace std;

class codigo {
public :
   ULong64_t migps[4601]; //define la variable migps, variable portable sin signo de 8 bytes.
   Int_t cont[4601]; //entero sin signo de 4 bytes.
   TH1D * h; //nombrando el histograma

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   UInt_t          ch11;  //varible entera sin signo de 4 bytes. Se crean las variables que son las ramas de los arboles.
   UInt_t          ch12;
   UInt_t          ch13;
   UInt_t          ch14;
   UInt_t          ch21;
   UInt_t          ch22;
   UInt_t          ch23;
   UInt_t          ch24;
   UInt_t          ch31;
   UInt_t          ch32;
   UInt_t          ch33;
   UInt_t          ch34;
   UInt_t          ch41;
   UInt_t          ch42;
   UInt_t          ch43;
   UInt_t          ch44;
   UInt_t          ch51;
   UInt_t          ch52;
   UInt_t          ch53;
   UInt_t          ch54;
   UInt_t          ch61;
   UInt_t          ch62;
   UInt_t          ch63;
   UInt_t          ch64;
   ULong64_t       gps;

   // List of branches
   TBranch        *b_ch11;   //! //se crean las ramas!
   TBranch        *b_ch12;   //!
   TBranch        *b_ch13;   //!
   TBranch        *b_ch14;   //!
   TBranch        *b_ch21;   //!
   TBranch        *b_ch22;   //!
   TBranch        *b_ch23;   //!
   TBranch        *b_ch24;   //!
   TBranch        *b_ch31;   //!
   TBranch        *b_ch32;   //!
   TBranch        *b_ch33;   //!
   TBranch        *b_ch34;   //!
   TBranch        *b_ch41;   //!
   TBranch        *b_ch42;   //!
   TBranch        *b_ch43;   //!
   TBranch        *b_ch44;   //!
   TBranch        *b_ch51;   //!
   TBranch        *b_ch52;   //!
   TBranch        *b_ch53;   //!
   TBranch        *b_ch54;   //!
   TBranch        *b_ch61;   //!
   TBranch        *b_ch62;   //!
   TBranch        *b_ch63;   //!
   TBranch        *b_ch64;   //!
   TBranch        *b_gps;   //!

   codigo(TTree *tree=0);
   codigo(string ss);
   virtual ~codigo();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop(string);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef codigo_cxx
codigo::codigo(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SierraNegra200811120500.root"); //recibe el archivo .dat
      if (!f) {
         f = new TFile("SierraNegra200811120500.root"); //genera el archivo .root
      }
      tree = (TTree*)gDirectory->Get("T"); 

   }
   Init(tree);
}

codigo::codigo(string s)
{
  TChain* ch = new TChain("T");
  ch->AddFile(s.data());
  Init(ch);
}

codigo::~codigo()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t codigo::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t codigo::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (!fChain->InheritsFrom(TChain::Class()))  return centry;
   TChain *chain = (TChain*)fChain;
   if (chain->GetTreeNumber() != fCurrent) {
      fCurrent = chain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void codigo::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("ch11", &ch11, &b_ch11);
   fChain->SetBranchAddress("ch12", &ch12, &b_ch12);
   fChain->SetBranchAddress("ch13", &ch13, &b_ch13);
   fChain->SetBranchAddress("ch14", &ch14, &b_ch14);
   fChain->SetBranchAddress("ch21", &ch21, &b_ch21);
   fChain->SetBranchAddress("ch22", &ch22, &b_ch22);
   fChain->SetBranchAddress("ch23", &ch23, &b_ch23);
   fChain->SetBranchAddress("ch24", &ch24, &b_ch24);
   fChain->SetBranchAddress("ch31", &ch31, &b_ch31);
   fChain->SetBranchAddress("ch32", &ch32, &b_ch32);
   fChain->SetBranchAddress("ch33", &ch33, &b_ch33);
   fChain->SetBranchAddress("ch34", &ch34, &b_ch34);
   fChain->SetBranchAddress("ch41", &ch41, &b_ch41);
   fChain->SetBranchAddress("ch42", &ch42, &b_ch42);
   fChain->SetBranchAddress("ch43", &ch43, &b_ch43);
   fChain->SetBranchAddress("ch44", &ch44, &b_ch44);
   fChain->SetBranchAddress("ch51", &ch51, &b_ch51);
   fChain->SetBranchAddress("ch52", &ch52, &b_ch52);
   fChain->SetBranchAddress("ch53", &ch53, &b_ch53);
   fChain->SetBranchAddress("ch54", &ch54, &b_ch54);
   fChain->SetBranchAddress("ch61", &ch61, &b_ch61);
   fChain->SetBranchAddress("ch62", &ch62, &b_ch62);
   fChain->SetBranchAddress("ch63", &ch63, &b_ch63);
   fChain->SetBranchAddress("ch64", &ch64, &b_ch64);
   fChain->SetBranchAddress("gps", &gps, &b_gps);
   Notify();
}

Bool_t codigo::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void codigo::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t codigo::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef codigo_cxx
