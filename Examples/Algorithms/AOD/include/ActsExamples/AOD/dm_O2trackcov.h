#include <TTree.h>
struct O2trackcov{
    float fSigmaY;
    float fSigmaZ;
    float fSigmaSnp;
    float fSigmaTgl;
    float fSigma1Pt;
    int8_t fRhoZY;
    int8_t fRhoSnpY;
    int8_t fRhoSnpZ;
    int8_t fRhoTglY;
    int8_t fRhoTglZ;
    int8_t fRhoTglSnp;
    int8_t fRho1PtY;
    int8_t fRho1PtZ;
    int8_t fRho1PtSnp;
    int8_t fRho1PtTgl;
    TTree *fTree;
    O2trackcov() {
        fTree = new TTree("O2trackcov", "");
        fTree->Branch("fSigmaY", &fSigmaY, "fSigmaY/F");
        fTree->Branch("fSigmaZ", &fSigmaZ, "fSigmaZ/F");
        fTree->Branch("fSigmaSnp", &fSigmaSnp, "fSigmaSnp/F");
        fTree->Branch("fSigmaTgl", &fSigmaTgl, "fSigmaTgl/F");
        fTree->Branch("fSigma1Pt", &fSigma1Pt, "fSigma1Pt/F");
        fTree->Branch("fRhoZY", &fRhoZY, "fRhoZY/B");
        fTree->Branch("fRhoSnpY", &fRhoSnpY, "fRhoSnpY/B");
        fTree->Branch("fRhoSnpZ", &fRhoSnpZ, "fRhoSnpZ/B");
        fTree->Branch("fRhoTglY", &fRhoTglY, "fRhoTglY/B");
        fTree->Branch("fRhoTglZ", &fRhoTglZ, "fRhoTglZ/B");
        fTree->Branch("fRhoTglSnp", &fRhoTglSnp, "fRhoTglSnp/B");
        fTree->Branch("fRho1PtY", &fRho1PtY, "fRho1PtY/B");
        fTree->Branch("fRho1PtZ", &fRho1PtZ, "fRho1PtZ/B");
        fTree->Branch("fRho1PtSnp", &fRho1PtSnp, "fRho1PtSnp/B");
        fTree->Branch("fRho1PtTgl", &fRho1PtTgl, "fRho1PtTgl/B");
    }
    ~O2trackcov() {
        delete fTree;
    }
    void fill() {
        fTree->Fill();
    }
    void write() {
        fTree->Write();
    }
};
