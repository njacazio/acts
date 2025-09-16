#include <TTree.h>
struct O2mccollislabel{
    uint64_t fIndexMcCollisions;
    uint16_t fMcMask;
    TTree *fTree;
    O2mccollislabel() {
        fTree = new TTree("O2mccollislabel", "");
        fTree->Branch("fIndexMcCollisions", &fIndexMcCollisions, "fIndexMcCollisions/I");
        fTree->Branch("fMcMask", &fMcMask, "fMcMask/s");
    }
    ~O2mccollislabel() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
