#include <TTree.h>
struct O2tracksextraa3{
    int fNSiliconHits;
    int fNTPCHits;
    TTree *fTree;
    O2tracksextraa3() {
        fTree = new TTree("O2tracksextraa3", "");
        fTree->Branch("fNSiliconHits", &fNSiliconHits, "fNSiliconHits/I");
        fTree->Branch("fNTPCHits", &fNTPCHits, "fNTPCHits/I");
    }
    ~O2tracksextraa3() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
