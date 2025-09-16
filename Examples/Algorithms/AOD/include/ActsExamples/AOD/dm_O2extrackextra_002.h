#include <TTree.h>
struct O2extrackextra_002{
    None fDetectorMap;
    TTree *fTree;
    O2extrackextra_002() {
        fTree = new TTree("O2extrackextra_002", "");
    }
    ~O2extrackextra_002() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
