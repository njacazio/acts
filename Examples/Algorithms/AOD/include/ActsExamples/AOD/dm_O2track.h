#include <TTree.h>
struct O2track{
    uint64_t fIndexCollisions;
    uint8_t fTrackType;
    float fX;
    float fAlpha;
    float fY;
    float fZ;
    float fSnp;
    float fTgl;
    float fSigned1Pt;
    TTree *fTree;
    O2track() {
        fTree = new TTree("O2track", "");
        fTree->Branch("fIndexCollisions", &fIndexCollisions, "fIndexCollisions/I");
        fTree->Branch("fTrackType", &fTrackType, "fTrackType/b");
        fTree->Branch("fX", &fX, "fX/F");
        fTree->Branch("fAlpha", &fAlpha, "fAlpha/F");
        fTree->Branch("fY", &fY, "fY/F");
        fTree->Branch("fZ", &fZ, "fZ/F");
        fTree->Branch("fSnp", &fSnp, "fSnp/F");
        fTree->Branch("fTgl", &fTgl, "fTgl/F");
        fTree->Branch("fSigned1Pt", &fSigned1Pt, "fSigned1Pt/F");
    }
    ~O2track() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
