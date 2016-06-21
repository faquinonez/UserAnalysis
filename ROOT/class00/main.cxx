#include <TCanvas.h>
#include <TH1F.h>

using namespace std;

int main()
{
  TCanvas* c = new TCanvas("c","c");
  c->cd();
  TH1F* h = new TH1F("h","h",24,-10,10);
  h->FillRandom("landau");
  h->Draw();
  c->cd();
  c->SetSelected(c);
  c->SaveAs("plot.png");
  c->SaveAs("plot.eps");
  c->Close();

  return 0;
}


