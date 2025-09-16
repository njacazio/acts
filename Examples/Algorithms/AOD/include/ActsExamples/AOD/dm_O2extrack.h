#include <TTree.h>
struct O2extrack{
    None fPt;
    None fP;
    None fEta;
    None fPhi;
    TTree *fTree;
    O2extrack() {
        fTree = new TTree("O2extrack", "");
    }
    ~O2extrack() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
