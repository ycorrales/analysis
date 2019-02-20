//make MVTX hit distributions
void plot_MVTX(){

  TCanvas * c1 = new TCanvas("c1","MVTX Telescope Simulations", 10, 20, 800,800);
  TCanvas * c2 = new TCanvas("c2","MVTX MC particles", 100, 200, 800,800);

  c1->cd();
  c1->Divide(2,3);

  c1->cd(1)->SetLogy();
  T->Draw("n_G4HIT_MVTX");

  c1->cd(2);
  T->Draw("G4HIT_MVTX[].y[0]:G4HIT_MVTX[].x[0]:G4HIT_MVTX[].z[0]","","cont");

  c1->cd(3);
  T->Draw("G4HIT_MVTX.z[][0]");

  c1->cd(4);
  T->Draw("G4HIT_MVTX[].y[0]:G4HIT_MVTX[].x[0]","","colz"); // lego/cont/colz

  c1->cd(5)->SetLogy();
  T->Draw("G4HIT_MVTX[].x[0]","","");

  c1->cd(6);
  T->Draw("G4HIT_MVTX[].y[0]","","");
  T->Draw("G4HIT_MVTX[].y[0]","","");


  //-- MC particle information 
  c2->cd();
  c2->Divide(2,3);

  c2->cd(1)->SetLogy();
  T->Draw("n_PHG4Particle");

  c2->cd(2);
  T->Draw("abs(PHG4Particle.fpid)","abs(PHG4Particle.fpid)<1000");
  //  T->Draw("PHG4Particle.fpid");

  c2->cd(3)->SetLogy();
  T->Draw("PHG4Particle.fpz","abs(PHG4Particle.fpid)<10000");

  c2->cd(4)->SetLogy(0);
  T->Draw("PHG4VtxPoint.vz","PHG4VtxPoint.vz>0");

  c2->cd(5)->SetLogz();
  T->Draw("PHG4Particle.fpz:PHG4VtxPoint.vz","PHG4VtxPoint.vz>0 ","colz");

  c2->cd(6)->SetLogy(0);
  T->Draw("abs(PHG4Particle.fpid):PHG4VtxPoint.vz","PHG4VtxPoint.vz>0  &&abs(PHG4Particle.fpid)<3000","colz");

}
