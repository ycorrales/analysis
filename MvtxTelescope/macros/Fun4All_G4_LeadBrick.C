//
// FErmilab test beam MC for MVTX telescope
// Jin's simple MC package 
// 
// switched to PHG4SimpelEventGenerator from PHG4ParticleGun
// 3/7/2018  MXL
//
#include <iostream>

using namespace std;

int Fun4All_G4_LeadBrick(const int nEvents = 10, const char *outfile = NULL)
{
  gSystem->Load("libfun4all");
  gSystem->Load("libg4detectors");
  gSystem->Load("libg4testbench");
  gSystem->Load("libg4eval");

  ///////////////////////////////////////////
  // Make the Server
  //////////////////////////////////////////
  Fun4AllServer *se = Fun4AllServer::instance();
  se->Verbosity(1);

  /*
  // particle gun
  PHG4ParticleGun *gun = new PHG4ParticleGun("PGUN");
  //  gun->set_name("anti_proton");
  gun->set_name("proton");
  //  gun->set_name("mu-");
  //  gun->set_name("proton");
  gun->set_vtx(0, 0, -100);
  gun->set_mom(0, 0, 120);
  se->registerSubsystem(gun);
  */

  // use simple event generator 
  PHG4SimpleEventGenerator * gun = new PHG4SimpleEventGenerator("evtgen");
  gun->add_particles(2212,1); // proton
  gun->set_p_range(119,121,1);
  gun->set_phi_range(0,3);  
  gun->set_eta_range(10,10);

  gun->set_vertex_distribution_function(PHG4SimpleEventGenerator::FUNCTION::Gaus,PHG4SimpleEventGenerator::FUNCTION::Gaus,PHG4SimpleEventGenerator::FUNCTION::Uniform);

  //  gun->set_vertex_distribution_mean(-0.057,-0.43,-100); // in cm
  gun->set_vertex_distribution_mean(0.0,0.0,-100); // in cm
  gun->set_vertex_distribution_width(0.24,0.35,0); // in cm

  //  gun->Verbosity(1);
  se->registerSubsystem(gun);

  // Fun4All G4 module
  PHG4Reco *g4Reco = new PHG4Reco();
  // no magnetic field
  g4Reco->set_field(0);
  // size of the world - every detector has to fit in here
  g4Reco->SetWorldSizeX(200);
  g4Reco->SetWorldSizeY(200);
  g4Reco->SetWorldSizeZ(200);
  // shape of our world - it is a box
  g4Reco->SetWorldShape("G4BOX");
  // this is what our world is filled with
  g4Reco->SetWorldMaterial("G4_AIR");
  // Geant4 Physics list to use
  g4Reco->SetPhysicsList("FTFP_BERT");

  // our block "detector", size is in cm
  double xsize = 200.;
  double ysize = 200.;
  double zsize = 400.;

  //lead briack = 2 x 5 x 9 inch; (5.08 x 12.7 x 22.86 cm)
  // 3 configurations: 1, 2, 4 lead bricks placed next to the telescope window
  PHG4BlockSubsystem *box = new PHG4BlockSubsystem("LeadBrick");
  box->set_double_param("size_x", 22.86);
  box->set_double_param("size_y", 12.70);
  box->set_double_param("size_z", 10.16); //dZ=5.08, 10.16(2), 20.32(4)

  // shift Lead brick so we do not create particles in its center and shift by 10 so we can see the track of the incoming particle
  box->set_double_param("place_z", 45.0);   // 1st brick @Z=47.5cm, center of block (1 brick);  Z =45cm(2 bricks); Z = 40cm(4 bricks);
  

  box->set_string_param("material", "G4_Pb");  // material of box
  box->SetActive(0);                           // if it is an active volume - save G4Hits
  g4Reco->registerSubsystem(box);

  //MAPS sensors
  for (int stave = 0; stave < 4; ++stave)
  {
    box = new PHG4BlockSubsystem("MVTX", stave);
    box->SuperDetector("MVTX");
    box->set_double_param("size_x", 1.5);                   // sensor:  3cm x 1.5cm x 100um used in the test beam 3/2018
    box->set_double_param("size_y", 3.0);
    box->set_double_param("size_z", 100e-4);              // 100um; 
    box->set_double_param("place_z", 2 * stave + 55);     // sensor-0 located at Z=55cm, telescope window @Z=50cm
    // shift sensor to 10cm down stream of Lead so we do not create particles in its center and shift by 2cm so we can see the track of the incoming particle

    box->set_string_param("material", "G4_Si");          // material of box
    box->SetActive(1);                                   // it is an active volume - save G4Hits
    g4Reco->registerSubsystem(box);
  }

  PHG4TruthSubsystem *truth = new PHG4TruthSubsystem();
  g4Reco->registerSubsystem(truth);

  se->registerSubsystem(g4Reco);

  ///////////////////////////////////////////
  // Output
  ///////////////////////////////////////////

  // save a comprehensive  evaluation file
  PHG4DSTReader *ana = new PHG4DSTReader(
					 string("LeadBrick_DSTReader.root"));
  ana->set_save_particle(true);
  ana->set_load_all_particle(false);
  ana->set_load_active_particle(true);
  ana->set_save_vertex(true);
  ana->AddNode("LeadBrick");
  ana->AddNode("MVTX");
  se->registerSubsystem(ana);

  // input - we need a dummy to drive the event loop
  Fun4AllInputManager *in = new Fun4AllDummyInputManager("JADE");
  se->registerInputManager(in);

  // a quick evaluator to inspect on hit/particle/tower level

  if (nEvents > 0)
  {
    se->run(nEvents);
    // finish job - close and save output files
    se->End();
    std::cout << "All done" << std::endl;

    // cleanup - delete the server and exit
    delete se;
    gSystem->Exit(0);
  }
  return;
}

PHG4ParticleGun *get_gun(const char *name = "PGUN")
{
  Fun4AllServer *se = Fun4AllServer::instance();
  PHG4ParticleGun *pgun = (PHG4ParticleGun *) se->getSubsysReco(name);
  return pgun;
}
