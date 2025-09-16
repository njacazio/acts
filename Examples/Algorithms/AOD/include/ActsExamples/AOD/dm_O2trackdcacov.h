#include <TTree.h>
struct O2trackdcacov{
    float fSigmaDcaXY2;
    float fSigmaDcaZ2;
    TTree *fTree;
    O2trackdcacov() {
        fTree = new TTree("O2trackdcacov", "");
        fTree->Branch("fSigmaDcaXY2", &fSigmaDcaXY2, "fSigmaDcaXY2/F");
        fTree->Branch("fSigmaDcaZ2", &fSigmaDcaZ2, "fSigmaDcaZ2/F");
    }
    ~O2trackdcacov() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
