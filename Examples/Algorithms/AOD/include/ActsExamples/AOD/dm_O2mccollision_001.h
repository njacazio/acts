#include <TTree.h>
struct O2mccollision_001{
    uint64_t fIndexBCs;
    short fGeneratorsID;
    float fPosX;
    float fPosY;
    float fPosZ;
    float fT;
    float fWeight;
    float fImpactParameter;
    float fEventPlaneAngle;
    TTree *fTree;
    O2mccollision_001() {
        fTree = new TTree("O2mccollision_001", "");
        fTree->Branch("fIndexBCs", &fIndexBCs, "fIndexBCs/I");
        fTree->Branch("fGeneratorsID", &fGeneratorsID, "fGeneratorsID/S");
        fTree->Branch("fPosX", &fPosX, "fPosX/F");
        fTree->Branch("fPosY", &fPosY, "fPosY/F");
        fTree->Branch("fPosZ", &fPosZ, "fPosZ/F");
        fTree->Branch("fT", &fT, "fT/F");
        fTree->Branch("fWeight", &fWeight, "fWeight/F");
        fTree->Branch("fImpactParameter", &fImpactParameter, "fImpactParameter/F");
        fTree->Branch("fEventPlaneAngle", &fEventPlaneAngle, "fEventPlaneAngle/F");
    }
    ~O2mccollision_001() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
