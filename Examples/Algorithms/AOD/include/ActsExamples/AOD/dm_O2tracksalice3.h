#include <TTree.h>
struct O2tracksalice3{
    bool fIsReconstructed;
    TTree *fTree;
    O2tracksalice3() {
        fTree = new TTree("O2tracksalice3", "");
        fTree->Branch("fIsReconstructed", &fIsReconstructed, "fIsReconstructed/O");
    }
    ~O2tracksalice3() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
