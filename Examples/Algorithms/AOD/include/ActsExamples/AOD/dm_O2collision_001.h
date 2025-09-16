#include <TTree.h>
struct O2collision_001{
    uint64_t fIndexBCs;
    float fPosX;
    float fPosY;
    float fPosZ;
    float fCovXX;
    float fCovXY;
    float fCovYY;
    float fCovXZ;
    float fCovYZ;
    float fCovZZ;
    uint32_t fFlags;
    float fChi2;
    uint16_t fNumContrib;
    float fCollisionTime;
    float fCollisionTimeRes;
    TTree *fTree;
    O2collision_001() {
        fTree = new TTree("O2collision_001", "");
        fTree->Branch("fIndexBCs", &fIndexBCs, "fIndexBCs/I");
        fTree->Branch("fPosX", &fPosX, "fPosX/F");
        fTree->Branch("fPosY", &fPosY, "fPosY/F");
        fTree->Branch("fPosZ", &fPosZ, "fPosZ/F");
        fTree->Branch("fCovXX", &fCovXX, "fCovXX/F");
        fTree->Branch("fCovXY", &fCovXY, "fCovXY/F");
        fTree->Branch("fCovYY", &fCovYY, "fCovYY/F");
        fTree->Branch("fCovXZ", &fCovXZ, "fCovXZ/F");
        fTree->Branch("fCovYZ", &fCovYZ, "fCovYZ/F");
        fTree->Branch("fCovZZ", &fCovZZ, "fCovZZ/F");
        fTree->Branch("fFlags", &fFlags, "fFlags/s");
        fTree->Branch("fChi2", &fChi2, "fChi2/F");
        fTree->Branch("fNumContrib", &fNumContrib, "fNumContrib/s");
        fTree->Branch("fCollisionTime", &fCollisionTime, "fCollisionTime/F");
        fTree->Branch("fCollisionTimeRes", &fCollisionTimeRes, "fCollisionTimeRes/F");
    }
    ~O2collision_001() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
