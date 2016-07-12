#define codigo_cxx
#include "codigo.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TPaveStats.h>
#include <TPave.h>
#include <TList.h>

#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>

using namespace std;

void codigo::Loop(string argumento1)
{
  h = new TH1D("h","histograma de marcas de gps",260,0,260);
  Int_t icol=0;
  gStyle->SetFrameBorderMode(icol);
  gStyle->SetFrameFillColor(icol);
  gStyle->SetCanvasBorderMode(icol);
  gStyle->SetCanvasColor(icol);
  gStyle->SetPadBorderMode(icol);
  gStyle->SetPadColor(icol);
  gStyle->SetStatColor(icol);
  gStyle->SetTitleFillColor(icol);

  gStyle->SetPadTopMargin(0.15);
  gStyle->SetPadRightMargin(0.26);
  gStyle->SetPadBottomMargin(0.16);
  gStyle->SetPadLeftMargin(0.12); 

  fChain->SetBranchStatus("*",1); 
  if (fChain == 0) return;

  ULong64_t mixmin, mixmax, nseg; 
  Long64_t nentries, nbytes, nb;

  nentries = fChain->GetEntries();
  if(nentries<540000 || nentries>900000){
    cout <<"\nNo pasa trigger de 25%  " <<argumento1<< endl;
    return;
  }
  if(nentries != 720000) cout << "nlines="<< nentries <<" file:" <<argumento1<< endl;

  nbytes = 0; 
  nb = 0;  

  nb = fChain->GetEntry(0);   
  mixmin=gps;
  nb = fChain->GetEntry(nentries-1);
  mixmax=gps;

  nseg = mixmax - mixmin + 1;
  for(ULong64_t i=0; i<nseg; i++){
    migps[i]=mixmin+i;
    cont[i]=0;
  }

  //nentries = fChain->GetEntriesFast();
  nbytes = 0; 
  nb = 0;
  for(Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if(ientry < 0) break;
    nb = fChain->GetEntry(jentry);   
    nbytes += nb;
    //cout << gps << endl;
    for(ULong64_t i=0; i<nseg; i++){

      if(migps[i]!=gps) continue;
      else{   
        cont[i]++;
      }

    }
  }

  for(ULong64_t i=0; i<nseg; i++){
    h->Fill(cont[i]);
  }

  //TCanvas *c = new TCanvas("c","c");
  //Double_t miIntegral = h->Integral();
  //Double_t norm = 1.0/( miIntegral );
    
  h->SetLineColor(kBlue);
  h->SetXTitle("Frecuencia de las marcas de GPS/1");
  //h->SetYTitle("Frecuencia de las frecuencias");
  //h->Scale(1.0/nseg);
  
  //h->Draw();
  //c->SaveAs("h.png");
  //delete h;
  //delete c;
  argumento1 = "histo" + argumento1;
  TFile * f = TFile::Open(argumento1.c_str(),"RECREATE");
  f->cd();
  h->Write();
  f->Close();
  
}

