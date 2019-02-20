void ana_T(){
//////////////////////////////////////////////////////////
//   This file has been automatically generated 
//     (Thu Mar  8 01:16:32 2018 by ROOT version5.34/36)
//   from TTree T/PHG4DSTReader
//   found on file: LeadBrick1_DSTReader_1K.root
//////////////////////////////////////////////////////////


//Reset ROOT and connect tree file
   gROOT->Reset();
   TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("LeadBrick1_DSTReader_1K.root");
   if (!f) {
      f = new TFile("LeadBrick1_DSTReader_1K.root");
   }
    f->GetObject("T",tree);

//Declaration of leaves types
   Int_t           n_G4HIT_LeadBrick;
   UInt_t          G4HIT_LeadBrick_fUniqueID[0];
   UInt_t          G4HIT_LeadBrick_fBits[0];
   Float_t         G4HIT_LeadBrick_x[0][2];
   Float_t         G4HIT_LeadBrick_y[0][2];
   Float_t         G4HIT_LeadBrick_z[0][2];
   Float_t         G4HIT_LeadBrick_t[0][2];
   ULong64_t       G4HIT_LeadBrick_hitid[0];
   Int_t           G4HIT_LeadBrick_trackid[0];
   Int_t           G4HIT_LeadBrick_showerid[0];
   Float_t         G4HIT_LeadBrick_edep[0];
   map<unsigned char,unsigned int> G4HIT_LeadBrick_prop_map[0];
   Float_t         G4HIT_LeadBrick_eion[0];
   Int_t           G4HIT_LeadBrick_scint_id[0];
   Float_t         G4HIT_LeadBrick_light_yield[0];
   Float_t         G4HIT_LeadBrick_path_length[0];
   Int_t           n_G4HIT_MVTX;
   UInt_t          G4HIT_MVTX_fUniqueID[274];
   UInt_t          G4HIT_MVTX_fBits[274];
   Float_t         G4HIT_MVTX_x[274][2];
   Float_t         G4HIT_MVTX_y[274][2];
   Float_t         G4HIT_MVTX_z[274][2];
   Float_t         G4HIT_MVTX_t[274][2];
   ULong64_t       G4HIT_MVTX_hitid[274];
   Int_t           G4HIT_MVTX_trackid[274];
   Int_t           G4HIT_MVTX_showerid[274];
   Float_t         G4HIT_MVTX_edep[274];
   map<unsigned char,unsigned int> G4HIT_MVTX_prop_map[274];
   Float_t         G4HIT_MVTX_eion[274];
   Int_t           G4HIT_MVTX_scint_id[274];
   Float_t         G4HIT_MVTX_light_yield[274];
   Float_t         G4HIT_MVTX_path_length[274];
   Int_t           n_PHG4Particle;
   UInt_t          PHG4Particle_fUniqueID[90];
   UInt_t          PHG4Particle_fBits[90];
   string          PHG4Particle_fname[90];
   Int_t           PHG4Particle_fpid[90];
   Double_t        PHG4Particle_fpx[90];
   Double_t        PHG4Particle_fpy[90];
   Double_t        PHG4Particle_fpz[90];
   Int_t           PHG4Particle_barcode[90];
   Int_t           PHG4Particle_trkid[90];
   Int_t           PHG4Particle_vtxid[90];
   Int_t           PHG4Particle_parentid[90];
   Int_t           PHG4Particle_primaryid[90];
   Double_t        PHG4Particle_fe[90];
   Int_t           n_PHG4VtxPoint;
   UInt_t          PHG4VtxPoint_fUniqueID[73];
   UInt_t          PHG4VtxPoint_fBits[73];
   Double_t        PHG4VtxPoint_vx[73];
   Double_t        PHG4VtxPoint_vy[73];
   Double_t        PHG4VtxPoint_vz[73];
   Double_t        PHG4VtxPoint_t0[73];
   Int_t           PHG4VtxPoint_id[73];

   // Set branch addresses.
   T->SetBranchAddress("n_G4HIT_LeadBrick",&n_G4HIT_LeadBrick);
   T->SetBranchAddress("G4HIT_LeadBrick",&G4HIT_LeadBrick_);
   T->SetBranchAddress("G4HIT_LeadBrick.fUniqueID",&G4HIT_LeadBrick_fUniqueID);
   T->SetBranchAddress("G4HIT_LeadBrick.fBits",&G4HIT_LeadBrick_fBits);
   T->SetBranchAddress("G4HIT_LeadBrick.x[2]",G4HIT_LeadBrick_x);
   T->SetBranchAddress("G4HIT_LeadBrick.y[2]",G4HIT_LeadBrick_y);
   T->SetBranchAddress("G4HIT_LeadBrick.z[2]",G4HIT_LeadBrick_z);
   T->SetBranchAddress("G4HIT_LeadBrick.t[2]",G4HIT_LeadBrick_t);
   T->SetBranchAddress("G4HIT_LeadBrick.hitid",&G4HIT_LeadBrick_hitid);
   T->SetBranchAddress("G4HIT_LeadBrick.trackid",&G4HIT_LeadBrick_trackid);
   T->SetBranchAddress("G4HIT_LeadBrick.showerid",&G4HIT_LeadBrick_showerid);
   T->SetBranchAddress("G4HIT_LeadBrick.edep",&G4HIT_LeadBrick_edep);
   T->SetBranchAddress("G4HIT_LeadBrick.prop_map",&G4HIT_LeadBrick_prop_map);
   T->SetBranchAddress("G4HIT_LeadBrick.eion",&G4HIT_LeadBrick_eion);
   T->SetBranchAddress("G4HIT_LeadBrick.scint_id",&G4HIT_LeadBrick_scint_id);
   T->SetBranchAddress("G4HIT_LeadBrick.light_yield",&G4HIT_LeadBrick_light_yield);
   T->SetBranchAddress("G4HIT_LeadBrick.path_length",&G4HIT_LeadBrick_path_length);
   T->SetBranchAddress("n_G4HIT_MVTX",&n_G4HIT_MVTX);
   T->SetBranchAddress("G4HIT_MVTX",G4HIT_MVTX_);
   T->SetBranchAddress("G4HIT_MVTX.fUniqueID",G4HIT_MVTX_fUniqueID);
   T->SetBranchAddress("G4HIT_MVTX.fBits",G4HIT_MVTX_fBits);
   T->SetBranchAddress("G4HIT_MVTX.x[2]",G4HIT_MVTX_x);
   T->SetBranchAddress("G4HIT_MVTX.y[2]",G4HIT_MVTX_y);
   T->SetBranchAddress("G4HIT_MVTX.z[2]",G4HIT_MVTX_z);
   T->SetBranchAddress("G4HIT_MVTX.t[2]",G4HIT_MVTX_t);
   T->SetBranchAddress("G4HIT_MVTX.hitid",G4HIT_MVTX_hitid);
   T->SetBranchAddress("G4HIT_MVTX.trackid",G4HIT_MVTX_trackid);
   T->SetBranchAddress("G4HIT_MVTX.showerid",G4HIT_MVTX_showerid);
   T->SetBranchAddress("G4HIT_MVTX.edep",G4HIT_MVTX_edep);
   T->SetBranchAddress("G4HIT_MVTX.prop_map",G4HIT_MVTX_prop_map);
   T->SetBranchAddress("G4HIT_MVTX.eion",G4HIT_MVTX_eion);
   T->SetBranchAddress("G4HIT_MVTX.scint_id",G4HIT_MVTX_scint_id);
   T->SetBranchAddress("G4HIT_MVTX.light_yield",G4HIT_MVTX_light_yield);
   T->SetBranchAddress("G4HIT_MVTX.path_length",G4HIT_MVTX_path_length);
   T->SetBranchAddress("n_PHG4Particle",&n_PHG4Particle);
   T->SetBranchAddress("PHG4Particle",&PHG4Particle_);
   T->SetBranchAddress("PHG4Particle.fUniqueID",PHG4Particle_fUniqueID);
   T->SetBranchAddress("PHG4Particle.fBits",PHG4Particle_fBits);
   T->SetBranchAddress("PHG4Particle.fname",PHG4Particle_fname);
   T->SetBranchAddress("PHG4Particle.fpid",PHG4Particle_fpid);
   T->SetBranchAddress("PHG4Particle.fpx",PHG4Particle_fpx);
   T->SetBranchAddress("PHG4Particle.fpy",PHG4Particle_fpy);
   T->SetBranchAddress("PHG4Particle.fpz",PHG4Particle_fpz);
   T->SetBranchAddress("PHG4Particle.barcode",PHG4Particle_barcode);
   T->SetBranchAddress("PHG4Particle.trkid",PHG4Particle_trkid);
   T->SetBranchAddress("PHG4Particle.vtxid",PHG4Particle_vtxid);
   T->SetBranchAddress("PHG4Particle.parentid",PHG4Particle_parentid);
   T->SetBranchAddress("PHG4Particle.primaryid",PHG4Particle_primaryid);
   T->SetBranchAddress("PHG4Particle.fe",PHG4Particle_fe);
   T->SetBranchAddress("n_PHG4VtxPoint",&n_PHG4VtxPoint);
   T->SetBranchAddress("PHG4VtxPoint",&PHG4VtxPoint_);
   T->SetBranchAddress("PHG4VtxPoint.fUniqueID",PHG4VtxPoint_fUniqueID);
   T->SetBranchAddress("PHG4VtxPoint.fBits",PHG4VtxPoint_fBits);
   T->SetBranchAddress("PHG4VtxPoint.vx",PHG4VtxPoint_vx);
   T->SetBranchAddress("PHG4VtxPoint.vy",PHG4VtxPoint_vy);
   T->SetBranchAddress("PHG4VtxPoint.vz",PHG4VtxPoint_vz);
   T->SetBranchAddress("PHG4VtxPoint.t0",PHG4VtxPoint_t0);
   T->SetBranchAddress("PHG4VtxPoint.id",PHG4VtxPoint_id);


   //-- define historgrams --

   TCanvas * c1 = new TCanvas("c1","MVTX Telescope simulations", 10, 20, 600, 600);


//     This is the loop skeleton
//       To read only selected branches, Insert statements like:
// T->SetBranchStatus("*",0);  // disable all branches
// TTreePlayer->SetBranchStatus("branchname",1);  // activate branchname

   Long64_t nentries = T->GetEntries();

   Long64_t nbytes = 0;
   for (Long64_t i=0; i<nentries;i++) {
     nbytes += T->GetEntry(i);
   }
// end of event loop


//make plots

   c1->cd();

}
