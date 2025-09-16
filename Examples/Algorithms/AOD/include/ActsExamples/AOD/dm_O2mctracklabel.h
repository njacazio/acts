#include <TTree.h>
struct O2mctracklabel{
    uint64_t fIndexMcParticles;
    uint16_t fMcMask;
    TTree *fTree;
    O2mctracklabel() {
        fTree = new TTree("O2mctracklabel", "");
        fTree->Branch("fIndexMcParticles", &fIndexMcParticles, "fIndexMcParticles/I");
        fTree->Branch("fMcMask", &fMcMask, "fMcMask/s");
    }
    ~O2mctracklabel() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
