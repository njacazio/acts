#include <TTree.h>
struct O2mcparticle_001{
    uint64_t fIndexMcCollisions;
    int fPdgCode;
    int fStatusCode;
    uint8_t fFlags;
    int fIndexArray_Mothers_size;
    std::vector<uint64_t> fIndexArray_Mothers;
    std::pair<uint64_t, uint64_t> fIndexSlice_Daughters;
    float fWeight;
    float fPx;
    float fPy;
    float fPz;
    float fE;
    float fVx;
    float fVy;
    float fVz;
    float fVt;
    TTree *fTree;
    O2mcparticle_001() {
        fTree = new TTree("O2mcparticle_001", "");
        fTree->Branch("fIndexMcCollisions", &fIndexMcCollisions, "fIndexMcCollisions/I");
        fTree->Branch("fPdgCode", &fPdgCode, "fPdgCode/I");
        fTree->Branch("fStatusCode", &fStatusCode, "fStatusCode/I");
        fTree->Branch("fFlags", &fFlags, "fFlags/b");
        fTree->Branch("fIndexArray_Mothers_size", &fIndexArray_Mothers_size, "fIndexArray_Mothers_size/I");
        fTree->Branch("fIndexArray_Mothers", &fIndexArray_Mothers, "fIndexArray_Mothers[fIndexArray_Mothers_size]/I");
        fTree->Branch("fIndexSlice_Daughters", &fIndexSlice_Daughters, "fIndexSlice_Daughters[2]/I");
        fTree->Branch("fWeight", &fWeight, "fWeight/F");
        fTree->Branch("fPx", &fPx, "fPx/F");
        fTree->Branch("fPy", &fPy, "fPy/F");
        fTree->Branch("fPz", &fPz, "fPz/F");
        fTree->Branch("fE", &fE, "fE/F");
        fTree->Branch("fVx", &fVx, "fVx/F");
        fTree->Branch("fVy", &fVy, "fVy/F");
        fTree->Branch("fVz", &fVz, "fVz/F");
        fTree->Branch("fVt", &fVt, "fVt/F");
    }
    ~O2mcparticle_001() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
