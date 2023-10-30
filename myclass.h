//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Oct 30 17:48:53 2023 by ROOT version 6.18/04
// from TTree run/run
// found on file: root://fndcadoor.fnal.gov/pnfs/fnal.gov/usr/mu2e/tape/phy-rec/rec/mu2e/CRV_wideband_cosmics/CRVWB-000-004-000/root/fb/27/rec.mu2e.CRV_wideband_cosmics.CRVWB-000-004-000.001365_000.root
//////////////////////////////////////////////////////////

#ifndef myclass_h
#define myclass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class myclass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           runNumber;
   Int_t           subrunNumber;
   Int_t           spillIndex;
   Int_t           spillNumber;
   Int_t           boardStatus[2][22];
   Long64_t        spillTimestamp;
   Int_t           eventNumber;
   Long64_t        tdcSinceSpill[2][64];
   Double_t        timeSinceSpill[2][64];
   Int_t           fitStatus[2][64];
   Float_t         PEs[2][64];
   Float_t         PEsTemperatureCorrected[2][64];
   Float_t         temperature[2][64];
   Float_t         pulseHeight[2][64];
   Float_t         beta[2][64];
   Float_t         time[2][64];
   Float_t         LEtime[2][64];
   Short_t         adc[2][64][127];
   Int_t           recoStartBin[2][64];
   Int_t           recoEndBin[2][64];
   Float_t         pedestal[2][64];
   Int_t           fitStatusReflectedPulse[2][64];
   Float_t         PEsReflectedPulse[2][64];
   Float_t         PEsTemperatureCorrectedReflectedPulse[2][64];
   Float_t         pulseHeightReflectedPulse[2][64];
   Float_t         betaReflectedPulse[2][64];
   Float_t         timeReflectedPulse[2][64];
   Float_t         LEtimeReflectedPulse[2][64];
   Int_t           recoStartBinReflectedPulse[2][64];
   Int_t           recoEndBinReflectedPulse[2][64];

   // List of branches
   TBranch        *b_runNumber;   //!
   TBranch        *b_subrunNumber;   //!
   TBranch        *b_spillIndex;   //!
   TBranch        *b_spillNumber;   //!
   TBranch        *b_boardStatus;   //!
   TBranch        *b_spillTimestamp;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_tdcSinceSpill;   //!
   TBranch        *b_timeSinceSpill;   //!
   TBranch        *b_fitStatus;   //!
   TBranch        *b_PEs;   //!
   TBranch        *b_PEsTemperatureCorrected;   //!
   TBranch        *b_temperature;   //!
   TBranch        *b_pulseHeight;   //!
   TBranch        *b_beta;   //!
   TBranch        *b_time;   //!
   TBranch        *b_LEtime;   //!
   TBranch        *b_adc;   //!
   TBranch        *b_recoStartBin;   //!
   TBranch        *b_recoEndBin;   //!
   TBranch        *b_pedestal;   //!
   TBranch        *b_fitStatusReflectedPulse;   //!
   TBranch        *b_PEsReflectedPulse;   //!
   TBranch        *b_PEsTemperatureCorrectedReflectedPulse;   //!
   TBranch        *b_pulseHeightReflectedPulse;   //!
   TBranch        *b_betaReflectedPulse;   //!
   TBranch        *b_timeReflectedPulse;   //!
   TBranch        *b_LEtimeReflectedPulse;   //!
   TBranch        *b_recoStartBinReflectedPulse;   //!
   TBranch        *b_recoEndBinReflectedPulse;   //!

   myclass(TTree *tree=0);
   virtual ~myclass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef myclass_cxx
myclass::myclass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("root://fndcadoor.fnal.gov/pnfs/fnal.gov/usr/mu2e/tape/phy-rec/rec/mu2e/CRV_wideband_cosmics/CRVWB-000-004-000/root/fb/27/rec.mu2e.CRV_wideband_cosmics.CRVWB-000-004-000.001365_000.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("root://fndcadoor.fnal.gov/pnfs/fnal.gov/usr/mu2e/tape/phy-rec/rec/mu2e/CRV_wideband_cosmics/CRVWB-000-004-000/root/fb/27/rec.mu2e.CRV_wideband_cosmics.CRVWB-000-004-000.001365_000.root");
      }
      f->GetObject("run",tree);

   }
   Init(tree);
}

myclass::~myclass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t myclass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t myclass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void myclass::Init(TTree *tree)
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

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("subrunNumber", &subrunNumber, &b_subrunNumber);
   fChain->SetBranchAddress("spillIndex", &spillIndex, &b_spillIndex);
   fChain->SetBranchAddress("spillNumber", &spillNumber, &b_spillNumber);
   fChain->SetBranchAddress("boardStatus", boardStatus, &b_boardStatus);
   fChain->SetBranchAddress("spillTimestamp", &spillTimestamp, &b_spillTimestamp);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("tdcSinceSpill", tdcSinceSpill, &b_tdcSinceSpill);
   fChain->SetBranchAddress("timeSinceSpill", timeSinceSpill, &b_timeSinceSpill);
   fChain->SetBranchAddress("fitStatus", fitStatus, &b_fitStatus);
   fChain->SetBranchAddress("PEs", PEs, &b_PEs);
   fChain->SetBranchAddress("PEsTemperatureCorrected", PEsTemperatureCorrected, &b_PEsTemperatureCorrected);
   fChain->SetBranchAddress("temperature", temperature, &b_temperature);
   fChain->SetBranchAddress("pulseHeight", pulseHeight, &b_pulseHeight);
   fChain->SetBranchAddress("beta", beta, &b_beta);
   fChain->SetBranchAddress("time", time, &b_time);
   fChain->SetBranchAddress("LEtime", LEtime, &b_LEtime);
   fChain->SetBranchAddress("adc", adc, &b_adc);
   fChain->SetBranchAddress("recoStartBin", recoStartBin, &b_recoStartBin);
   fChain->SetBranchAddress("recoEndBin", recoEndBin, &b_recoEndBin);
   fChain->SetBranchAddress("pedestal", pedestal, &b_pedestal);
   fChain->SetBranchAddress("fitStatusReflectedPulse", fitStatusReflectedPulse, &b_fitStatusReflectedPulse);
   fChain->SetBranchAddress("PEsReflectedPulse", PEsReflectedPulse, &b_PEsReflectedPulse);
   fChain->SetBranchAddress("PEsTemperatureCorrectedReflectedPulse", PEsTemperatureCorrectedReflectedPulse, &b_PEsTemperatureCorrectedReflectedPulse);
   fChain->SetBranchAddress("pulseHeightReflectedPulse", pulseHeightReflectedPulse, &b_pulseHeightReflectedPulse);
   fChain->SetBranchAddress("betaReflectedPulse", betaReflectedPulse, &b_betaReflectedPulse);
   fChain->SetBranchAddress("timeReflectedPulse", timeReflectedPulse, &b_timeReflectedPulse);
   fChain->SetBranchAddress("LEtimeReflectedPulse", LEtimeReflectedPulse, &b_LEtimeReflectedPulse);
   fChain->SetBranchAddress("recoStartBinReflectedPulse", recoStartBinReflectedPulse, &b_recoStartBinReflectedPulse);
   fChain->SetBranchAddress("recoEndBinReflectedPulse", recoEndBinReflectedPulse, &b_recoEndBinReflectedPulse);
   Notify();
}

Bool_t myclass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void myclass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t myclass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef myclass_cxx
