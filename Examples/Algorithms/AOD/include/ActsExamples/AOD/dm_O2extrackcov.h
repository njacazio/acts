#include <TTree.h>
struct O2extrackcov{
    None fCYY;
    None fCZY;
    None fCZZ;
    None fCSnpY;
    None fCSnpZ;
    None fCSnpSnp;
    None fCTglY;
    None fCTglZ;
    None fCTglSnp;
    None fCTglTgl;
    None fC1PtY;
    None fC1PtZ;
    None fC1PtSnp;
    None fC1PtTgl;
    None fC1Pt21Pt2;
    TTree *fTree;
    O2extrackcov() {
        fTree = new TTree("O2extrackcov", "");
    }
    ~O2extrackcov() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
