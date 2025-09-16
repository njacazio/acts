#include <TTree.h>
struct O2trackdca{
    float fDcaXY;
    float fDcaZ;
    TTree *fTree;
    O2trackdca() {
        fTree = new TTree("O2trackdca", "");
        fTree->Branch("fDcaXY", &fDcaXY, "fDcaXY/F");
        fTree->Branch("fDcaZ", &fDcaZ, "fDcaZ/F");
    }
    ~O2trackdca() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
