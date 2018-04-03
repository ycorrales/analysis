#ifndef __RICHEvaluator_H__
#define __RICHEvaluator_H__

#include <fun4all/SubsysReco.h>
#include <math.h>

class TTree;
class TFile;
class TH1D;

class PHCompositeNode;
class PHG4TruthInfoContainer;
class PHG4Hit;
class PHG4HitContainer;
class SvtxTrackMap;
class SvtxTrack_FastSim;
class TDatabasePDG;

class TrackProjectorRICH;
class SetupDualRICHAnalyzer;

class RICHEvaluator : public SubsysReco
{

public:

  RICHEvaluator(std::string tracksname, std::string richname, std::string filename);

  int
  Init(PHCompositeNode*);
  int
  InitRun(PHCompositeNode*);
  int
  process_event(PHCompositeNode*);
  int
  End(PHCompositeNode*);

  /* set name of the track state inside the RICH radiator volume */
  void set_trackstate_name( std::string newname )
  {
    _trackstate_name = newname;
    return;
  }

  /* set refractive index of RICH radiator */
  void set_refractive_index( float newidx )
  {
    _refractive_index = newidx;
    return;
  }

private:

  /** reset all output tree variables */
  void reset_tree_vars();

  /** initialize output tree(s) */
  int init_tree();
  int init_tree_small();

  /** calculate true Cerenkov light emission angle from truth particle information */
  double calculate_true_emission_angle( PHG4TruthInfoContainer* truthinfo, SvtxTrack_FastSim * track, double index );

  /** calculate mass for single track and photon */
  double calculate_reco_mass( double mom, double theta_reco, double index );

  /** calculate true particle mass from truth particle information */
  double calculate_true_mass( PHG4TruthInfoContainer* truthinfo, SvtxTrack_FastSim * track);

  bool _verbose;

  int _ievent;

  /* Collection sotring track information */
  std::string _trackmap_name;

  /* Hit collection storing RICH photon hits */
  std::string _richhits_name;

  /* Name of the track state inside the RICH radiator volume */
  std::string _trackstate_name;

  /* Refractive index of RICH radiator */
  float _refractive_index;

  /* ROOT file to store output ROOT tree */
  std::string _foutname;
  TFile *_fout_root;

  /* output tree and variables */
  TTree* _tree_rich;
  TTree* _tree_rich_small;

  double _hit_x0;
  double _hit_y0;
  double _hit_z0;

  double _emi_x;
  double _emi_y;
  double _emi_z;

  double _track_px;
  double _track_py;
  double _track_pz;

  double _mtrack_px;
  double _mtrack_py;
  double _mtrack_pz;
  double _mtrack_ptot;

  double _track_e;
  double _mtrack_e;
  double _edep;

  int _bankid;
  int _volumeid;
  int _hitid;
  int _pid;
  int _mpid;
  int _trackid;
  int _mtrackid;
  int _otrackid;

  float _theta_true;
  float _theta_reco;
  double _theta_mean;
  double _theta_rms;

  float _mass_true;
  float _mass_reco;

  /* track projector object */
  TrackProjectorRICH *_trackproj;

  /* acquire object */
  SetupDualRICHAnalyzer *_acquire;

  /* PDG databse access object */
  TDatabasePDG *_pdg;

};

#endif // __RICHEvaluator_H__
