#include <TTree.h>
struct O2collalice3{
    float fMultDensity;
    TTree *fTree;
    O2collalice3() {
        fTree = new TTree("O2collalice3", "");
        fTree->Branch("fMultDensity", &fMultDensity, "fMultDensity/F");
    }
    ~O2collalice3() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
