#ifndef AnalysisDataFormats_SkimEvent_h
#define AnalysisDataFormats_SkimEvent_h

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/ParameterSet/interface/FileInPath.h"
#include "DataFormats/Candidate/interface/LeafCandidate.h"
#include "DataFormats/Common/interface/RefToBase.h"
#include "DataFormats/Common/interface/Ref.h"
#include <DataFormats/Common/interface/Ptr.h>
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/Math/interface/Point3D.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/METFwd.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETFwd.h"
#include "DataFormats/METReco/interface/GenMET.h"
#include "DataFormats/METReco/interface/GenMETFwd.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

#include "SimDataFormats/HTXS/interface/HiggsTemplateCrossSections.h"

//---- pat
#include <DataFormats/PatCandidates/interface/MET.h>

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"

#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "SimDataFormats/GeneratorProducts/interface/GenFilterInfo.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHERunInfoProduct.h"

//---- latino default value
#include "LatinoTrees/DataFormats/interface/DefaultValues.h"



#include <vector>
#include <utility>

using std::size_t;

const double Mw = 80.450;
const double Mz = 91.188;


//---- index struct

struct indexValueStruct {
  indexValueStruct(const float &v, size_t i) : value(v), index(i) {}
  float value;
  size_t index;
};




namespace reco {
  
  struct mwlSortByPtClass {
    bool operator() ( edm::RefToBase<Candidate> a, edm::RefToBase<Candidate> b) { return a->pt() > b->pt(); }
  };
  
  /*
   s truct* sortPatJetByPtClass {
   bool operator() ( pat::JetRef a, pat::JetRef b) { return a.get()->pt() > b.get()->pt(); }
};
*/
  
  class SkimEvent : public LeafCandidate {
    
  public:
    
    // our base object for the leptons now
    //typedef edm::RefToBase<reco::RecoCandidate> refToCand;
    typedef edm::Ptr<reco::RecoCandidate> refToCand;
    
    //             enum hypoType {undefined = 0, WELNU = 1, WMUNU=2, WWELEL=3, WWELMU=4, WWMUEL=5, WWMUMU=6, hypoTypeSize=7};
    enum primaryDatasetType {MC = 0, SingleMuon=1, SingleElectron=2, DoubleMuon=3, MuEG=4, DoubleEG=5, primaryDatasetTypeSize=6, AllEmbed=7, MET=8, SinglePhoton=9};
    //enum metType { TCMET=0, PFMET=1, CHMET=2, MINMET=3 };
    enum metType { TCMET=0, PFMET=1, CHMET=2};
    
    //             static const std::string hypoTypeNames[];
    
    /// static functions used to convert to&from hypoType and strings
    //             static std::string hypoTypeName(SkimEvent::hypoType);
    //             static hypoType hypoTypeByName(const std::string &name);
    
    
    SkimEvent();
    //             SkimEvent(const hypoType &);
    
    //
    float userFloat( const std::string & key ) const;
    float userFloat( const char* key ) const { return userFloat( std::string(key) ); }
    
    void addUserFloat( const std::string & label, float data );
    const std::vector<std::string> & userFloatNames() const { return userFloatLabels_; }
    bool hasUserFloat( const std::string & key ) const {
      return std::find(userFloatLabels_.begin(), userFloatLabels_.end(), key) != userFloatLabels_.end();
    }
    bool hasUserFloat( const char* key ) const {return hasUserFloat( std::string(key) );}
    
    int32_t userInt( const std::string & key ) const;
    void addUserInt( const std::string & label, int32_t data );
    const std::vector<std::string> & userIntNames() const { return userIntLabels_; }
    bool hasUserInt( const std::string & key ) const {
      return std::find(userIntLabels_.begin(), userIntLabels_.end(), key) != userIntLabels_.end();
    }
    
    
    //Lepton variables
    //const bool passMuID0() const;
    //const bool passMuID1() const;
    //const bool passMuID2() const;
    //const bool passMuID3() const;
    //const bool passMuID4() const;
    //const bool passMuID5() const;
    //const bool passMuID6() const;
    //at userFloat( const std::string & key ) const;
    //00316 float userFloat( const char* key ) const { return userFloat( std::string(key) ); }
    //00317
    //00319 void addUserFloat( const std::string & label, float data );
    //00321 const std::vector<std::string> & userFloatNames() const { return userFloatLabels_; }
    //00323 bool hasUserFloat( const std::string & key ) const {
    //00324 return std::find(userFloatLabels_.begin(), userFloatLabels_.end(), key) != userFloatLabels_.end();
    //00325 }
    //00327 bool hasUserFloat( const char* key ) const {return hasUserFloat( std::string(key) );}
    //00328
    //00331 int32_t userInt( const std::string & key ) const;
    //00333 void addUserInt( const std::string & label, int32_t data );
    //00335 const std::vector<std::string> & userIntNames() const { return userIntLabels_; }
    //00337 bool hasUserInt( const std::string & key ) const {
    //00338 return std::find(userIntLabels_.begin(), userIntLabels_.end(), key) != userIntLabels_.end();
    //00339 }
    //00340
    //const bool passMuID7() const;
    //const bool passMuID8() const;
    
    // const float mcGenWeight () const { return mcGenWeight_; }
    const float mcGenWeight () const { return mcGenWeight_.filterEfficiency(); }
    
    const bool isElectron(size_t a) const;
    const bool isMuon(size_t a) const;
    const bool isElectron(const refToCand&) const;
    const bool isMuon(const refToCand&) const;
    
    const pat::Electron * getElectron(size_t a) const;
    const pat::Muon * getMuon(size_t a) const;
    const pat::Electron * getElectron(const refToCand&) const;
    const pat::Muon * getMuon(const refToCand&) const;
    
    //             const int hypo() const { return hypo_; }
    const int channel() const ;
    const int nLep(float a = -1) const;
    const int nExtraLep(float a = -1) const;
    const int nSoftMu(float a = -1, float vetoJets=-1, float dRCut = 0.3) const;
    const int pdgId(size_t a = 0) const;
    const int flavour(size_t a = 0) const;
    
    
    
    void FindDaughterParticles(const reco::Candidate** pCurrent, std::vector<const reco::Candidate*>* pFinal = 0) const;
    const float getFinalStateMC() const;
    const float getWWdecayMC() const;
    const float mcHiggsProd() const;
    
    //---- MC weights: -1 for SM; 0,1,2,... for parameters variation
    const float LHEMCweight(int i) const ;
    const float LHEMCweightID(int i) const ;
    const float GENMCweight(int i) const ;
    
    const float HEPMCweight() const ;
    const float HEPMCweightScale(size_t i) const ;
    const float HEPMCweightRen(size_t i) const ;
    const float HEPMCweightFac(size_t i) const ;
    
    const float getHiggsMass() const;
    const float getHiggsPt() const;
    const float getHiggsEta() const;
    const float getHiggsPhi() const;
    const float getSusyStopMass() const;
    const float getSusyLSPMass() const;
    const float susyParticlePt (size_t i) const;
    const float susyParticleEta(size_t i) const;
    const float susyParticlePhi(size_t i) const;
    const int   susyParticleID (size_t i) const;
    
    const float getPDFscalePDF() const;
    const float getPDFx1() const;
    const float getPDFx2() const;
    const float getPDFid1() const;
    const float getPDFid2() const;
    const float getPDFx1PDF() const;
    const float getPDFx2PDF() const;
    
    //const pat::Muon& mu(size_t a=0) const;
    //const pat::Electron& el(size_t a=0) const;
    
    const float pt(size_t a = 0) const;
    const int passCustom(size_t a = 0,const std::string &muStr="1", const std::string &elStr="1" ) const;
    //             const float leptId(size_t i, std::string idele = "", std::string idmu = "") const;             
    const float leptId(std::string idele = "", std::string idmu = "", size_t i=0) const;
    const float leptBdt(size_t a = 0) const;
    const float leptLH(size_t a = 0) const;
    const float ptMax() const { return ptByPt(0); }
    const float ptMin() const { return ptByPt(1); }
    const float eta(size_t a = 0) const;
    const float nBrem(size_t a = 0) const;
    const float etaSC(size_t a = 0) const; //returns isMuon ? defaultFloat : ele.sc.eta
    const float etaSCSeed(size_t a = 0) const;
    const float phi(size_t a = 0) const;
    const int   q(size_t a = 0) const;
    
    const bool peaking() const;
    const reco::GenParticle *genParticle(size_t i) const;
    const reco::GenParticleRef getMotherID(size_t a=0) const;
    
    //Jet variables
    const size_t indexJetByPt(size_t i, float minPt,float eta,int applyCorrection,int applyID) const;
    const size_t indexJetByPt(size_t i, float minPt,float eta,int applyCorrection,int applyID,float dzCut) const;
    const size_t indexSecondJetByPt(size_t i, float minPt,float eta,int applyCorrection,int applyID) const;
    
    const math::XYZTLorentzVector jet(size_t index, float minPt,float eta,int applyCorrection,int applyID) const;
    const int   nJets(float pt , int applyCorrection , int applyID) const;
    const int   nCentralJets(float pt , float eta,int applyCorrection=true, int applyID=0) const;
    const float leadingVBFJetPt(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const float leadingVBFJetEta(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const float leadingVBFJetPhi(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const int   leadingVBFJetId(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const float leadingVBFJetMva(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const pat::Jet* leadingJet(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    
    const float leadingJetPt (size_t a) const;
    const float leadingJetEta(size_t a) const;
    const float leadingJetPhi(size_t a) const;
    const float leadingJetMass(size_t a) const;
    const float leadingJetPUjetid(size_t a) const ;
    
    const float leadingJetPtRaw(size_t a) const;
    const float leadingJetPtL1 (size_t a) const;
    const float leadingJetPtL2 (size_t a) const;
    const float leadingJetPtL3Absolute (size_t a) const;
    const float leadingJetArea (size_t a) const;

    const float leadingJetChargedHadronFraction (size_t a) const;
    
    const float leadingJetPt(float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingJetEta(float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingJetPhi(float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingJetMass(float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingJetPUjetid(float pt,float eta,int applyCorrection,int applyID, size_t a) const;
    
    
    //             const float leadingJetPt(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    //             const float leadingJetEta(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    //             const float leadingJetMass(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    //             const float leadingJetPhi(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    
    const float leadingSecondJetPt(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const float leadingSecondJetEta(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const float leadingSecondJetPhi(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    
    const float leadingSecondJetPt(size_t a) const;
    const float leadingSecondJetEta(size_t a) const;
    const float leadingSecondJetPhi(size_t a) const;
    
    const float leadingFatJetPt(float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetEta(float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPhi(float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    
    const float leadingFatJetTrimmedMass (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetFilteredMass (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPrunedMass (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    
    const float leadingFatJetMassDrop (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPrunedTau2Tau1 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPrunedTau1 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPrunedTau2 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPrunedTau3 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPrunedTau4 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    
    const float leadingFatJetPuppiPt   (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPuppiEta  (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPuppiPhi  (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPuppiMass (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPuppiTau1 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPuppiTau2 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    const float leadingFatJetPuppiTau3 (float pt ,float eta,int applyCorrection, int applyID, size_t a) const;
    
    
    
    const float leadingJetPtd(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetPtD(size_t index, float minPt,float eta,int applyCorrection,int applyID, int QualityCut) const ;
    
    const float leadingJetQGaxis1(size_t index) const ;
    const float leadingJetQGaxis2(size_t index) const ;
    const float leadingJetQGRMScand(size_t index) const ;
    const float leadingJetQGRmax(size_t index) const ;
    const float leadingJetQGlikelihood(size_t index) const ;
    const float leadingJetQGlikelihoodAxis2(size_t index) const ;
    const float leadingJetQGlikelihoodMult(size_t index) const ;
    const float leadingJetQGlikelihoodPtD(size_t index) const ;
    
    const float leadingJetQGaxis1(size_t index, float minPt,float eta,int applyCorrection,int applyID, int QualityCut) const ;
    const float leadingJetQGaxis2(size_t index, float minPt,float eta,int applyCorrection,int applyID, int QualityCut) const ;
    const float leadingJetQGRMScand(size_t index, float minPt,float eta,int applyCorrection,int applyID, int QualityCut) const ;
    const float leadingJetQGRmax(size_t index, float minPt,float eta,int applyCorrection,int applyID, int QualityCut) const ;
    const float leadingJetQGlikelihood(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetQGlikelihoodAxis2(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetQGlikelihoodMult(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetQGlikelihoodPtD(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    
    const float leadingJetNChgQC(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetNChgptCut(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetNNeutralptCut(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    
    const float leadingJetChargedHadronMultiplicity(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetNeutralHadronMultiplicity(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float leadingJetPhotonMultiplicity(size_t index, float minPt,float eta,int applyCorrection,int applyID) const ;
    const float getJetRhoIso() const ;
    const float getJetRhoCaloIso() const ;
    const float getJetRhoCentralNeutralIso() const ;
    
    
    const int   leadingJetId(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const float leadingJetMva(size_t a, float pt ,float eta,int applyCorrection, int applyID) const;
    const float dPhillLeadingJet(float eta,int applyCorrection, int applyID) const;
    const bool  passesDPhillJet(float pt,float eta,int applyCorrection, int applyID) const;
    
    const float jetPt(size_t a = 0,int = 0) const;
    const float secondJetPt(size_t a = 0,int = 0) const;
    const float fatJetPt(size_t a = 0,int = 0) const;
    
    const float jetPt(const pat::Jet *j,int = 0) const;
    const float tagJetPt(size_t a = 0,int = 0) const;
    static void setupJEC(const std::string&, const std::string&, const std::string&);
    const float nearestJet(int i=0,float minPt=25, float eta=5.0,bool applyCorrection=1, int applyID=0 ) const;
    const pat::JetRef matchedJet(size_t alepton, float minDr=0.4) const;
    const float matchedJetPt(size_t alepton, float minDr=0.4, bool applyCorrection=1) const;
    const bool isThisJetALepton(pat::JetRef jet, float drCut=0.3, float minLeptonPt = 10.0) const ;
    
    const bool passJetID (pat::JetRef jet,int) const ;
    const bool passFatJetID (pat::JetRef jet,int) const ;
    
    const float leadingJetCloseLeptonPt(size_t ilepton, float ptminjet ,float etamaxjet,int applyCorrection, int applyID) const;
    const float leadingJetCloseLeptonEta(size_t ilepton, float ptminjet ,float etamaxjet,int applyCorrection, int applyID) const;
    const float leadingJetCloseLeptonPhi(size_t ilepton, float ptminjet ,float etamaxjet,int applyCorrection, int applyID) const;
    const float leadingJetCloseLeptonFlavour(size_t ilepton, float ptminjet ,float etamaxjet,int applyCorrection, int applyID) const;            
    const float leadingJetCloseLeptonDR(size_t ilepton, float ptminjet ,float etamaxjet,int applyCorrection, int applyID) const;            
    
    const float leadingJetCloseLeptonPt(size_t ilepton) const;
    const float leadingJetCloseLeptonEta(size_t ilepton) const;
    const float leadingJetCloseLeptonPhi(size_t ilepton) const;
    const float leadingJetCloseLeptonFlavour(size_t ilepton) const;            
    const float leadingJetCloseLeptonDR(size_t ilepton) const;            
    
    
    const float dPhiJetllInDegrees(size_t a,float pt ,float eta,int applyCorrection, int applyID) const;
    const float dPhiJetll(size_t a,float pt ,float eta,int applyCorrection, int applyID) const;
    //             const int leadingJetIndex(size_t index,float minPt,float eta,int applyCorrection,int applyID) const;
    const float dPhilljetjet(float eta,int applyCorrection,int applyID) const;
    //Event variables
    const float mTHiggs(metType metToUse=TCMET) const;
    const float tcMetX() const;
    const float pXll() const;
    const float tcMetY() const;
    const float pYll() const;
    const float mTll() const;
    const bool leptEtaCut(float maxAbsEtaMu=2.4,float maxAbsEtaEl=2.5) const;
    void setTriggerBits( const std::vector<bool> &);
    void setSelectedTriggerBits( const std::vector<float> &);
    void setSelectedTriggerBitsPrescales( const std::vector<float> &);
    void setSelectedTriggerL1minBitsPrescales( const std::vector<float> &);
    void setSelectedTriggerL1maxBitsPrescales( const std::vector<float> &);
    void setSpecialTriggerBits( const std::vector<float> &);
    
    
    const bool triggerBitsCut(SkimEvent::primaryDatasetType pdType) const;
    const bool guillelmoTrigger(SkimEvent::primaryDatasetType pdType) const;
    const bool fakeRateTrigger(SkimEvent::primaryDatasetType pdType) const;
    const bool triggerMatchingCut(SkimEvent::primaryDatasetType pdType) const;
    const float selectedRateTrigger(size_t i) const;
    const float selectedRateTriggerPrescale(size_t i) const;
    const float selectedRateTriggerL1minPrescale(size_t i) const;
    const float selectedRateTriggerL1maxPrescale(size_t i) const;
    const float specialRateTrigger(size_t i) const;
    
    bool passTriggerSingleMu(size_t i, bool isData=true) const;
    bool passTriggerDoubleMu(size_t i, bool isData=true) const;
    bool passTriggerElMu(size_t i, bool isData=true) const;
    bool passTriggerDoubleEl(size_t i, bool isData=true) const;
    
    void setElectronIds( const std::vector <std::string> &);
    void addElectronId (const std::vector<bool> &s, std::string name);
    //             void addElectronId (const edm::Handle<edm::ValueMap<bool> > &s, std::string name);
    void addElectronMvaId (const std::vector<float> &s, std::string name);
    
    const float met(metType metToUse=TCMET) const;
    
    const float metPfRaw() const;
    const float metPfRawJetEnUp() const;
    const float metPfRawJetEnDn() const;
    const float metPfRawJetResUp() const;
    const float metPfRawJetResDn() const;
    const float metPfRawMuonEnUp() const;
    const float metPfRawMuonEnDn() const;
    const float metPfRawElecEnUp() const;
    const float metPfRawElecEnDn() const;
    const float metPfRawUnclEnUp() const;
    const float metPfRawUnclEnDn() const;
    
    const float metPfRawPhi() const;
    const float metPfRawPhiJetEnUp() const;
    const float metPfRawPhiJetEnDn() const;
    const float metPfRawPhiJetResUp() const;
    const float metPfRawPhiJetResDn() const;
    const float metPfRawPhiMuonEnUp() const;
    const float metPfRawPhiMuonEnDn() const;
    const float metPfRawPhiElecEnUp() const;
    const float metPfRawPhiElecEnDn() const;
    const float metPfRawPhiUnclEnUp() const;
    const float metPfRawPhiUnclEnDn() const;
    
    const float metPfRawSumEt() const;
    
    
    const float metPfType1() const;
    const float metPfType1JetEnUp() const;
    const float metPfType1JetEnDn() const;
    const float metPfType1JetResUp() const;
    const float metPfType1JetResDn() const;
    const float metPfType1MuonEnUp() const;
    const float metPfType1MuonEnDn() const;
    const float metPfType1ElecEnUp() const;
    const float metPfType1ElecEnDn() const;
    const float metPfType1UnclEnUp() const;
    const float metPfType1UnclEnDn() const;
    
    const float metPfType1Phi() const;
    const float metPfType1PhiJetEnUp() const;
    const float metPfType1PhiJetEnDn() const;
    const float metPfType1PhiJetResUp() const;
    const float metPfType1PhiJetResDn() const;
    const float metPfType1PhiMuonEnUp() const;
    const float metPfType1PhiMuonEnDn() const;
    const float metPfType1PhiElecEnUp() const;
    const float metPfType1PhiElecEnDn() const;
    const float metPfType1PhiUnclEnUp() const;
    const float metPfType1PhiUnclEnDn() const;

    const float metPfType1SumEt() const;
    const float metPfNoHf() const;
    const float metPfUncorr() const;
    const float metPfMuEGClean() const;
    const float metPfMuEGCleanPhi() const;
    
    const float metPfProj() const;
    const float metPfProjJetEnUp() const;
    const float metPfProjJetEnDn() const;
    const float metPfProjJetResUp() const;
    const float metPfProjJetResDn() const;
    const float metPfProjMuonEnUp() const;
    const float metPfProjMuonEnDn() const;
    const float metPfProjElecEnUp() const;
    const float metPfProjElecEnDn() const;
    const float metPfProjUnclEnUp() const;
    const float metPfProjUnclEnDn() const;
    
    const float pupMet() const;
    const float trkMet() const;
    const float trkMetphi() const;
    const float mvaMet() const{return mvaMet_.pt();}
    const float mvaMetPhi() const{return mvaMet_.phi();}
    const float tcSumEt() const;
    const float tcMet() const;
    const float tcMetPhi() const;
    const float chargedSumEt() const;
    const float chargedMet() const;
    const float chargedMetSmurfSumEt() const;
    const float chargedMetSmurf() const{return chargedMetSmurf_.pt();}
    const float chargedMetSmurfPhi() const{return chargedMetSmurf_.phi();}
    const float pfMetSignificance() const;
    const float pfMetMEtSig() const;
    
    // MET XYshift
    const int hEtaPlus_counts() const;
    const int hEtaMinus_counts() const;
    const int h0Barrel_counts() const;
    const int h0EndcapPlus_counts() const;
    const int h0EndcapMinus_counts() const;
    const int gammaBarrel_counts() const;
    const int gammaEndcapPlus_counts() const;
    const int gammaEndcapMinus_counts() const;
    const int hHFPlus_counts() const;
    const int hHFMinus_counts() const;
    const int egammaHFPlus_counts() const;
    const int egammaHFMinus_counts() const;
    
    const double hEtaPlus_sumPt() const;
    const double hEtaMinus_sumPt() const;
    const double h0Barrel_sumPt() const;
    const double h0EndcapPlus_sumPt() const;
    const double h0EndcapMinus_sumPt() const;
    const double gammaBarrel_sumPt() const;
    const double gammaEndcapPlus_sumPt() const;
    const double gammaEndcapMinus_sumPt() const;
    const double hHFPlus_sumPt() const;
    const double hHFMinus_sumPt() const;
    const double egammaHFPlus_sumPt() const;
    const double egammaHFMinus_sumPt() const;

    const float dmZllReco() const;
    
    void set_XYshift_sumPt(
      double hEtaPlus_sumPt, double inhEtaMinus_sumPt, double h0Barrel_sumPt,
      double h0EndcapPlus_sumPt, double h0EndcapMinus_sumPt, double gammaBarrel_sumPt,
      double gammaEndcapPlus_sumPt, double gammaEndcapMinus_sumPt, double hHFPlus_sumPt,
      double hHFMinus_sumPt, double egammaHFPlus_sumPt, double egammaHFMinus_sumPt );
    
    void set_XYshift_counts(
      int hEtaPlus_counts, int hEtaMinus_counts, int h0Barrel_counts,
      int h0EndcapPlus_counts, int h0EndcapMinus_counts, int gammaBarrel_counts,
      int gammaEndcapPlus_counts, int gammaEndcapMinus_counts, int hHFPlus_counts,
      int hHFMinus_counts, int egammaHFPlus_counts, int egammaHFMinus_counts );
    
    // Gen ZGstar
    const float Gen_ZGstar_mu1_pt()  const{ return muon1FromGstar.pt;}
    const float Gen_ZGstar_mu1_eta() const{ return muon1FromGstar.eta;}
    const float Gen_ZGstar_mu1_phi() const{ return muon1FromGstar.phi;}
    
    const float Gen_ZGstar_mu2_pt()  const{ return muon2FromGstar.pt;}
    const float Gen_ZGstar_mu2_eta() const{ return muon2FromGstar.eta;}
    const float Gen_ZGstar_mu2_phi() const{ return muon2FromGstar.phi;}
    
    const float Gen_ZGstar_MomId() const{ return MomInfo.id;}
    const float Gen_ZGstar_MomStatus() const{ return MomInfo.status;}
    const float Gen_ZGstar_MomInitStatus() const{ return MomInfo.initStatus;}
    
    const float Gen_ZGstar_mass() const{ return genDiLeptMassZGstar;}
    const float Gen_ZGstar_deltaR() const{ return _ZGstarDiLept_DelaR;}
    
    const float Gen_ZGstar_ele1_pt()  const{ return elec1FromGstar.pt;}
    const float Gen_ZGstar_ele1_eta() const{ return elec1FromGstar.eta;}
    const float Gen_ZGstar_ele1_phi() const{ return elec1FromGstar.phi;}
    
    const float Gen_ZGstar_ele2_pt()  const{ return elec2FromGstar.pt;}
    const float Gen_ZGstar_ele2_eta() const{ return elec2FromGstar.eta;}
    const float Gen_ZGstar_ele2_phi() const{ return elec2FromGstar.phi;}
    
    //const float minMet() const;
    //const math::XYZTLorentzVector minMetP4() const;
    const float mll() const;
    const float pTll() const;
    const float dPhill() const;
    const float dPhillInDegrees() const {return dPhill() / M_PI * 180.;}
    const float dRll() const;
    const float dEtall() const;
    const float etall() const;
    const float yll() const;
    const float dPhillMet(metType metToUse=TCMET) const;
    const float dPhillPfMet() const;
    const float dPhillTcMet() const;
    const float dPhillChargedMet() const;
    //const float dPhillMinMet() const;
    const float mT(size_t a = 0, metType metToUse=TCMET) const;
    const float dPhilPfMet(size_t a) const;
    const float dPhilPfMetJetEnUp(size_t a) const;
    const float dPhilPfMetJetEnDn(size_t a) const;
    const float dPhilPfMetJetResUp(size_t a) const;
    const float dPhilPfMetJetResDn(size_t a) const;
    const float dPhilPfMetMuonEnUp(size_t a) const;
    const float dPhilPfMetMuonEnDn(size_t a) const;
    const float dPhilPfMetElecEnUp(size_t a) const;
    const float dPhilPfMetElecEnDn(size_t a) const;
    const float dPhilPfMetUnclEnUp(size_t a) const;
    const float dPhilPfMetUnclEnDn(size_t a) const;
    const float dPhilMvaMet(size_t a) const;
    const float dPhilTcMet(size_t a) const;
    const float dPhilChargedMet(size_t a) const;
    const float dPhilChargedMetSmurf(size_t a) const;
    //const float dPhilMinMet(size_t a) const;
    const float dPhilMet(metType metToUse=TCMET) const;
    const float dPhilMet(size_t a, metType metToUse=TCMET) const;
    const float dPhilPfMet() const;
    const float dPhilPfMetJetEnUp() const;
    const float dPhilPfMetJetEnDn() const;
    const float dPhilPfMetJetResUp() const;
    const float dPhilPfMetJetResDn() const;
    const float dPhilPfMetMuonEnUp() const;
    const float dPhilPfMetMuonEnDn() const;
    const float dPhilPfMetElecEnUp() const;
    const float dPhilPfMetElecEnDn() const;
    const float dPhilPfMetUnclEnUp() const;
    const float dPhilPfMetUnclEnDn() const;
    const float dPhilMvaMet() const;
    const float dPhilTcMet() const;
    const float dPhilChargedMet() const;
    const float dPhilChargedMetSmurf() const;
    //const float dPhilMinMet() const;
    const float projMet(metType metToUse=TCMET) const;
    const float projMvaMet() const;
    const float projTcMet() const;
    const float projChargedMet() const;
    const float projChargedMetSmurf() const;
    //const float projMinMet() const;
    //const float pfMT(size_t a = 0) const;
    //const float tcMT(size_t a = 0) const;
    //const float pfMTll(size_t a = 0, size_t b = 1) const;
    //const float tcMTll(size_t a = 0, size_t b = 1) const;
    //const float llType(size_t a = 0, size_t b = 1) const;
    const float nTracks() const;
    //const float dPhiJetTcMet(size_t a = 0, size_t b = 1) const;
    //const float dPhiJetPfMet(size_t a = 0, size_t b = 1) const;
    const float cosThetaStar(size_t a = 0) const;
    const float afb(size_t a = 0) const;
    //const size_t dPhiPfMetMin(size_t a=0, size_t b=0) const;
    //const size_t dPhiTcMetMin(size_t a=0, size_t b=0) const;
    const float mRStar() const;
    const float gamma() const;
    const float gammaMRStar() const;
    
    // Selection functions
    const bool   passesIP() const;
    const bool   passesIP(const refToCand &c) const;
    const bool   hasGoodVertex() const;
    const double d0Reco              (size_t a=0) const;
    const double dZReco              (size_t a=0) const;
    const double d0RecoByPt          (size_t a=0) const { return d0Reco          (indexByPt(a)); }
    const double dZRecoByPt          (size_t a=0) const { return dZReco          (indexByPt(a)); }
    const bool   isSTA(size_t a=0) const;
    const bool   isSTA(const refToCand &c) const;
    const bool   isMuTriggered(size_t a=0) const;
    
    
    const float leadingTauPt (size_t a) const;
    const float leadingTauEta(size_t a) const;
    const float leadingTauPhi(size_t a) const;

    const float leadingTauVLooseIsoMvaNew(size_t a) const;
    const float leadingTauLooseIsoMvaNew(size_t a) const;
    const float leadingTauMediumIsoMvaNew(size_t a) const;
    const float leadingTauTightIsoMvaNew(size_t a) const;
    const float leadingTauVTightIsoMvaNew(size_t a) const;

    const float leadingTauVLooseIsoMvaOld(size_t a) const;
    const float leadingTauLooseIsoMvaOld(size_t a) const;
    const float leadingTauMediumIsoMvaOld(size_t a) const;
    const float leadingTauTightIsoMvaOld(size_t a) const;
    const float leadingTauVTightIsoMvaOld(size_t a) const;

    const float leadingTauLooseIsoDbeta (size_t a) const;
    const float leadingTauMediumIsoDbeta (size_t a) const;
    const float leadingTauTightIsoDbeta (size_t a) const;   

    
    const int numberOfbQuarks() const;
    const int numberOftQuarks() const;
    
    const float leadingLHEJetPt(size_t a) const;
    const float leadingLHEJetPID(size_t a) const;
    const float leadingLHEJetPhi(size_t a) const;
    const float leadingLHEJetEta(size_t a) const;
    const float leadingLHELeptonPt(size_t a) const;
    const float leadingLHELeptonPID(size_t a) const;
    const float leadingLHELeptonPhi(size_t a) const;
    const float leadingLHELeptonEta(size_t a) const;
    const float leadingLHENeutrinoPt(size_t a) const;
    const float leadingLHENeutrinoPID(size_t a) const;
    const float leadingLHENeutrinoPhi(size_t a) const;
    const float leadingLHENeutrinoEta(size_t a) const;
    
    const float LHEMetPt() const;
    const float LHEMetPhi() const;
    const float LHEMetEta() const;
    
    const float higgsLHEPt() const;
    const float higgsLHEEta() const;
    const float higgsLHEPhi() const;
    const float higgsLHEmass() const;

    const float partonLHEPt(int id) const;
    const float partonLHEEta(int id) const;
    const float partonLHEPhi(int id) const;
    const float partonLHEmass(int id) const;
    
    const float leadingGenJetPartonPt(size_t a) const;
    const float leadingGenJetPartonPID(size_t a) const;
    const float leadingGenJetPartonEta(size_t a) const;
    const float leadingGenJetPartonPhi(size_t a) const;
    const float leadingGenJetPartonIsPrompt(size_t a) const;
    const float leadingGenJetPartonIsHardProcess(size_t a) const;
    
    // Compatible with PYTHIA8
    const int   originalStatus(const reco::Candidate* p) const;
    const float genLeptonPt          (size_t a) const;
    const float genLeptonEta         (size_t a) const;
    const float genLeptonPhi         (size_t a) const;
    const float genLeptonPID         (size_t a) const;
    const float genLeptonStatus      (size_t a) const;
    const float genLeptonIsPrompt    (size_t a) const;
    const float genLeptonIsDirectPromptTauDecayProduct  (size_t a) const;
    const float genLeptonIsTauDecayProduct              (size_t a) const;
    const float genLeptonIsDirectHadronDecayProduct     (size_t a) const;
    const float genLeptonFromHardProcess                (size_t a) const;
    const float genLeptonIndex       (size_t a) const;
    const float genLeptonMotherPID   (size_t a) const;
    const float genLeptonMotherStatus(size_t a) const;
    
    const float genVBosonPt          (size_t a) const;
    const float genVBosonEta         (size_t a) const;
    const float genVBosonPhi         (size_t a) const;
    const float genVBosonMass        (size_t a) const;
    const float genVBosonPID         (size_t a) const;
    const float genVBosonStatus      (size_t a) const;
    const float genVBosonIsHardProcess(size_t a) const;
    const float genVBosonFromHardProcessBeforeFSR(size_t a) const;

    const float GenDarkMatterPt(size_t a) const;
    
    const float leadingGenNeutrinoPt(size_t a) const;
    const float leadingGenNeutrinoPID(size_t a) const;
    const float leadingGenNeutrinoEta(size_t a) const;
    const float leadingGenNeutrinoPhi(size_t a) const;
    const float leadingGenNeutrinoIsPrompt(size_t a) const;
    const float leadingGenNeutrinoIsDirectPromptTauDecayProduct(size_t a) const;
    const float leadingGenNeutrinoMotherPID(size_t a) const;
    const float leadingGenNeutrinoMotherStatus(size_t a) const;
    
    const float leadingGenJetPt(size_t a) const;
    const float leadingGenJetEta(size_t a) const;
    const float leadingGenJetPhi(size_t a) const;
    
    const float genPhotonPt           (size_t a) const;
    const float genPhotonPhi          (size_t a) const;
    const float genPhotonEta          (size_t a) const;
    const float genPhotonMotherPID    (size_t a) const;
    const float genPhotonMotherStatus (size_t a) const;
    
    const float genMetPt() const;
    const float genMetPhi() const;
    const float genMetEta() const;
    
    const math::XYZTLorentzVector lepton(size_t a) const;
    
    //void setLepton(const pat::Electron& ele);
    //void setLepton(const pat::Muon& mu);
    //void setSoftMuon(const pat::Muon& mu);
    //void setExtraLepton(const pat::Electron& ele);
    //void setExtraLepton(const pat::Muon& mu);
    void setEventInfo  (const edm::Event &e) { run_ = e.id().run(); lumi_ = e.id().luminosityBlock(); evt_ = e.id().event(); }
    void setLepton     (const edm::Handle<edm::View<reco::RecoCandidate> > &h, size_t i);
    void setSoftMuon   (const edm::Handle<edm::View<reco::RecoCandidate> > &h, size_t i);
    void setExtraLepton(const edm::Handle<edm::View<reco::RecoCandidate> > &h, size_t i);

    void setPFCollection(const edm::Handle<pat::PackedCandidateCollection> &);
    
    void setTaus(const edm::Handle<pat::TauCollection> &);
    
    void setJetRhoIso(const edm::Handle<double> & h);
    void setJetRhoCaloIso(const edm::Handle<double> & h);
    void setJetRhoCentralNeutralIso(const edm::Handle<double> & h);
    
    void setJets(const edm::Handle<pat::JetCollection> &);
    void setFatJets(const edm::Handle<pat::JetCollection> &);
    void setTagJets(const edm::Handle<pat::JetCollection> &);
    void setSecondJets(const edm::Handle<pat::JetCollection> &);
    void setTrackJets(const edm::Handle<pat::JetCollection> &);
    void setTCMet(const edm::Handle<reco::METCollection> &);
    void setPFMet(const edm::Handle< std::vector<pat::MET> > &);
    void setPFMetNoHf(const edm::Handle< std::vector<pat::MET> > &);
    void setUncorrPFMet(const edm::Handle< std::vector<pat::MET> > &);
    void setMuEGCleanPFMet(const edm::Handle< std::vector<pat::MET> > &);
    void setPUpMet(const edm::Handle< std::vector<pat::MET> > &);
    void setTrkMet(const reco::MET &);
    void setMvaMet(const reco::PFMET &met) {mvaMet_ = met;}
    void setChargedMet(const reco::PFMET &);
    void setChargedMetSmurf(const reco::MET& met) {chargedMetSmurf_ = met;}
    void setVertex(const edm::Handle<reco::VertexCollection> &);
    void setVtxSumPts(const edm::Handle<edm::ValueMap<float> > &s);
    void setVtxSumPt2s(const edm::Handle<edm::ValueMap<float> > &s);
    
    void setGenDiLeptFromZGstar( edm::Handle<reco::GenParticleCollection> genParticles);
    void setGenParticles(const edm::Handle<reco::GenParticleCollection> &h);
    void setGenLeptonIndices();
    void setDressedLepton(const edm::Handle<edm::View<reco::Candidate> > &h, size_t i);
    void setHTXS(const edm::Handle<HTXS::HiggsClassification>& htxsH);
    
    // void setGenWeight(const edm::Handle<double> &s);
    void setGenWeight(const edm::Handle<GenFilterInfo> &s);
    
    void setLHEinfo(const edm::Handle<LHEEventProduct> &h);
    void setLHEinfo(const edm::Handle<LHEEventProduct> &h,const edm::Handle<LHERunInfoProduct> &productLHERunInfoHandle);
    void setGenInfo(const edm::Handle<GenEventInfoProduct> &s);
    void setGenMet(const edm::Handle< std::vector<pat::MET> > &); //---- new interface to GenMET with miniAOD
    void setGenMet(const edm::Handle<reco::GenMETCollection> &);
    void setGenJets(const edm::Handle<reco::GenJetCollection> &);
    
    void setApplyJetCleaning(int applyJetCleaning);
    void setMaxEtaForJets(double value);
    void setMinPtForJets(double value);            
    void setDzCutForBtagJets(double value);
    void setApplyCorrectionForJets(bool flag);
    void setApply50nsValues(bool flag);
    void setApplyIDForJets(int jetidvalue); 
    
    void setPuJetIdDiscriminantName(std::string pujetiddiscriminant); 
    
    void setMaxDrSoftMuonJet(double value);
    void setMinPtSoftMuon(double value);
    
    
    //void sortJetsByPt() { std::sort(jets_.begin(), jets_.end(), sortPatJetByPt); }
    //void sortTagJetsByPt() { std::sort(tagJets_.begin(), tagJets_.end(), sortPatJetByPt); }
    
    const unsigned int run() const { return run_; }
    const unsigned int lumi() const { return lumi_; }
    const unsigned int evt() const { return evt_; }
    
    const bool passesVtxSel(size_t a=0) const;
    const reco::Vertex highestPtVtx() const;
    const int bTaggedJetsBetween(const float& minPt,const float& maxPt, const float& discrCut, std::string discriminator="trackCountingHighEffBJetTags", int applyID=0, float dzCut=9999.) const;
    const int bTaggedJetsUnder(const float& maxPt, const float& discrCut, std::string discriminator="trackCountingHighEffBJetTags", int applyID=0, float dzCut=9999.) const;
    const int bTaggedJetsOver(const float& maxPt, const float& discrCut, std::string discriminator="trackCountingHighEffBJetTags", int applyID=0, float dzCut=9999.) const;
    
    const float leadingJetBtag(size_t a, std::string discriminator="trackCountingHighEffBJetTags",float pt=30.0 ,float eta=5.0,int applyCorrection=true, int applyID=0, float dzCut=9999.) const;
    const float highestBDiscRange(const float& minPt, const float& maxPt, std::string discriminator="trackCountingHighEffBJetTags", int applyID=0, float dzCut=9999., int minPtApplyCorrection =0) const;
    const float highestHardBDisc(const float& maxPt, std::string discriminator="trackCountingHighEffBJetTags", int applyID=0, float dzCut=9999.) const;
    const float highestSoftBDisc(const float& maxPt, std::string discriminator="trackCountingHighEffBJetTags", int applyID=0, float dzCut=9999.) const;
    
    const float leadingJetPUid(size_t a, float pt , float eta=5.0,int applyCorrection=true, int applyID=0, float dzCut=9999.) const;
    const float leadingJetPUid(size_t a) const;
    
    //---- jet and MC
    const float leadingJetPartonFlavour(size_t a, float pt , float eta=5.0,int applyCorrection=true, int applyID=0, float dzCut=9999.) const;
    const float leadingJetPartonFlavour(size_t a) const;
    const float leadingJetHadronFlavour(size_t a, float pt , float eta=5.0,int applyCorrection=true, int applyID=0, float dzCut=9999.) const;
    const float leadingJetHadronFlavour(size_t a) const;
    
    // Track Jets
    float sumHtTrackJets() const;
    float sumHtTrackJetsDensity() const;
    float multiplicityTrackJets() const;
    float multiplicityTrackJetsDensity() const;
    float trackJetPt(size_t i) const;
    float trackJetEta(size_t i) const;
    float trackJetPhi(size_t i) const;
    float trackJetProbabilityB(size_t i) const;
    
    //Iso Functions
    const bool isEB(size_t a = 0) const;
    const bool isEE(size_t a = 0) const;
    const float tkPt(size_t a = 0) const;
    
    const size_t indexByPt(size_t a = 0) const;
    const size_t indexByPtSoftMuon(size_t a = 0) const;
    const size_t indexByIso(size_t a = 0) const;
    
    const float tkIso(size_t a = 0) const;
    const float ecalIso(size_t a = 0) const;
    const float hcalIso(size_t a = 0) const;
    const float getRho(size_t a = 0) const;
    const float allIso(size_t a = 0) const;
    const float mvaIso(size_t a = 0) const;
    
    const float tkVeto(size_t a = 0) const;
    const float ecalVeto(size_t a = 0) const;
    const float hcalVeto(size_t a = 0) const;
    const float allVeto(size_t a = 0) const;
    
    const reco::Candidate & candByPt(size_t i) const { return *leps_[indexByPt(i)]; }
    
    const float isSTAByPt (size_t i = 0) const { return isSTA (indexByPt (i)); }
    const float tkIsoByPt (size_t i = 0) const { return tkIso (indexByPt (i)); }
    const float tkIsoByIso (size_t i = 0) const { return tkIso (indexByIso(i)); }
    const float ecalIsoByPt (size_t i = 0) const { return ecalIso(indexByPt (i)); }
    const float ecalIsoByIso(size_t i = 0) const { return ecalIso(indexByIso(i)); }
    const float hcalIsoByPt (size_t i = 0) const { return hcalIso(indexByPt (i)); }
    const float hcalIsoByIso(size_t i = 0) const { return hcalIso(indexByIso(i)); }
    const float allIsoByPt (size_t i = 0) const { return allIso (indexByPt (i)); }
    const float allIsoByIso (size_t i = 0) const { return allIso (indexByIso(i)); }
    const float mvaIsoByPt (size_t i = 0) const { return mvaIso (indexByPt (i)); }
    const float mvaIsoByIso (size_t i = 0) const { return mvaIso (indexByIso(i)); }
    const float tkVetoByPt (size_t i = 0) const { return tkVeto (indexByPt (i)); }
    const float tkVetoByIso (size_t i = 0) const { return tkVeto (indexByIso(i)); }
    const float ecalVetoByPt (size_t i = 0) const { return ecalVeto(indexByPt (i)); }
    const float ecalVetoByIso(size_t i = 0) const { return ecalVeto(indexByIso(i)); }
    const float hcalVetoByPt (size_t i = 0) const { return hcalVeto(indexByPt (i)); }
    const float hcalVetoByIso(size_t i = 0) const { return hcalVeto(indexByIso(i)); }
    const float allVetoByPt (size_t i = 0) const { return allVeto (indexByPt (i)); }
    const float allVetoByIso (size_t i = 0) const { return allVeto (indexByIso(i)); }
    const int flavourByPt (size_t i = 0) const { return flavour (indexByPt (i)); }
    const int pdgIdByPt (size_t i = 0) const { return pdgId (indexByPt (i)); }
    const int pdgIdByIso (size_t i = 0) const { return pdgId (indexByIso(i)); }
    const float ptByPt (size_t i = 0) const { return pt (indexByPt (i)); }
    const float leptIdByPt (std::string idele = "", std::string idmu = "", size_t i = 0) const { return leptId (idele, idmu, indexByPt (i)); }
    const float leptBdtByPt (size_t i = 0) const { return leptBdt (indexByPt (i)); }
    const float leptLHByPt (size_t i = 0) const { return leptLH (indexByPt (i)); }
    const float nBremByPt (size_t i = 0) const { return nBrem (indexByPt (i)); }
    const float ptByIso (size_t i = 0) const { return pt (indexByIso(i)); }
    const float etaByPt (size_t i = 0) const { return eta (indexByPt (i)); }
    const float R9ByPt (size_t i = 0) const { return R9 (indexByPt (i)); }
    const float full5x5R9ByPt (size_t i = 0) const { return full5x5R9 (indexByPt (i)); }
    
    const float FbremByPt      (size_t i = 0) const { return Fbrem (indexByPt (i)); }
    const float SeedEnergyByPt (size_t i = 0) const { return SeedEnergy (indexByPt (i)); }
    const float Energy5x5ByPt  (size_t i = 0) const { return Energy5x5 (indexByPt (i)); }
    
    const float tripleChargeAgreementByPt  (size_t i = 0) const { return tripleChargeAgreement (indexByPt (i)); }
    
    const float etaByIso (size_t i = 0) const { return eta (indexByIso(i)); }
    const float etaSCByPt (size_t i = 0) const { return etaSC (indexByPt (i)); }
    const float etaSCSeedByPt (size_t i = 0) const { return etaSCSeed (indexByPt (i)); }
    const float etaSCByIso (size_t i = 0) const { return etaSC (indexByIso(i)); }
    const float phiByPt (size_t i = 0) const { return phi (indexByPt (i)); }
    const float phiByIso (size_t i = 0) const { return phi (indexByIso(i)); }
    const int qByPt (size_t i = 0) const { return q (indexByPt (i)); }
    const int qByIso (size_t i = 0) const { return q (indexByIso(i)); }
    const bool isEBByPt (size_t i = 0) const { return isEB (indexByPt (i)); }
    const bool isEBByIso (size_t i = 0) const { return isEB (indexByIso(i)); }
    const float tkPtByPt (size_t i = 0) const { return tkPt (indexByPt (i)); }
    const float tkPtByIso (size_t i = 0) const { return tkPt (indexByIso(i)); }
    const float mTByPt(size_t i = 0, metType metToUse=TCMET) const { return mT(indexByPt(i), metToUse); }
    const float dPhilMetByPt(size_t i = 0, metType metToUse=TCMET) const { return dPhilMet(indexByPt(i),metToUse); }
    const int passCustomByPt(size_t i,std::string &a,const std::string &b) const { return passCustom(indexByPt (i),a,b); }
    
    //dressed lepton
    const size_t dressed_indexByPt(size_t a = 0) const;
    const float dressed_pt(size_t i = 0) const;
    const float dressed_eta(size_t i = 0) const;
    const float dressed_phi(size_t i = 0) const;
    const float dressed_pdgId(size_t i = 0) const;
    const float dressedLepton_ptByPt (size_t i = 0)   const { return dressed_pt    (dressed_indexByPt (i)); }
    const float dressedLepton_etaByPt(size_t i = 0)   const { return dressed_eta   (dressed_indexByPt (i)); }
    const float dressedLepton_phiByPt(size_t i = 0)   const { return dressed_phi   (dressed_indexByPt (i)); }
    const float dressedLepton_pdgIdByPt(size_t i = 0) const { return dressed_pdgId (dressed_indexByPt (i)); }
    // HTXS 
    const float HTXS_stage0() const;
    const float HTXS_stage1_pTjet30GeV() const;
    const float HTXS_stage1_pTjet25GeV() const;
    
    const float HTXS_ptjet25GeV (size_t i = 0) const;
    const float HTXS_etajet25GeV(size_t i = 0) const;

    const float HTXS_njets30() const;
    
    const float HTXS_ptHiggs() const;
    const float HTXS_etaHiggs() const;
    
      
    const int vtxSize() const { return vtxs_.size(); }
    const int nGoodVertices() const;
    const int mitType() const;
    
    const bool passesSmurfMuonID() const;
    const bool isHardMuID(size_t a) const;
    
    
    // Muon ID
    const int   muNValidHitsInTrk(size_t i) const;
    const float muNValidFractInTrk(size_t i) const;
    const float muNormChi2GTrk(size_t i) const;
    const int   muNValidHitsSATrk(size_t i) const;
    const int   muNumOfMatchedStations(size_t i) const;
    //             const float muBestTrackdz(size_t i) const;
    //             const float muBestTrackdxy(size_t i) const;
    const int   muNValidPixelHitsInTrk(size_t i) const;
    const int   muNTkLayers(size_t i) const;
    const float muTrkKink(size_t  i) const;
    const float muChi2LocalPos(size_t i) const;
    const float muSegCompatibilty(size_t i) const;
    
    const int   muNValidHitsInTrkByPt(size_t i) const {return muNValidHitsInTrk(indexByPt (i)); }    
    const float muNValidFractInTrkByPt(size_t i) const {return muNValidFractInTrk(indexByPt (i));}
    const float muNormChi2GTrkByPt(size_t i) const { return muNormChi2GTrk(indexByPt (i)); }
    const int   muNValidHitsSATrkByPt(size_t i) const { return muNValidHitsSATrk(indexByPt (i)); }
    const int   muNumOfMatchedStationsByPt(size_t i) const { return muNumOfMatchedStations(indexByPt (i)); }
    //             const float muBestTrackdzByPt(size_t i) const {return muBestTrackdz(indexByPt (i)); }
    //             const float muBestTrackdxyByPt(size_t i) const {return muBestTrackdxy(indexByPt (i)); }
    const int   muNValidPixelHitsInTrkByPt(size_t i) const {return muNValidPixelHitsInTrk(indexByPt (i)); }
    const int   muNTkLayersByPt(size_t i) const {return muNTkLayers(indexByPt (i)); }
    const float muTrkKinkByPt(size_t  i) const {return muTrkKink(indexByPt (i)); }
    const float muChi2LocalPosByPt(size_t i) const {return muChi2LocalPos(indexByPt (i)); }
    const float muSegCompatibiltyByPt(size_t i) const {return muSegCompatibilty(indexByPt (i)); }
    
    const bool isMediumMuon     (size_t i) const;
    //const bool isTrackerMuon    (size_t i) const;
    const bool isTightMuon      (size_t i) const;
    const bool isMediumMuonByPt(size_t i) const {return isMediumMuon(indexByPt (i)); }
    //const bool isTrackerMuonByPt(size_t i) const {return isTrackerMuon(indexByPt (i)); }
    const bool isTightMuonByPt (size_t i) const {return isTightMuon (indexByPt (i)); }
    
    const float SIP3D(size_t i) const;
    const float SIP3DByPt(size_t i) const {return SIP3D(indexByPt (i)); };
    
    
    // Electron ID
    void InitEffectiveAreasElectrons();
    
    const float GetElectronEffectiveArea      (size_t i, bool apply50nsValues) const;
    const float deltaEtaEleClusterTrackAtCalo (size_t i) const;   
    const float deltaEtaSeedClusterTrackAtCalo(size_t i) const;           
    const float deltaEtaSuperClusterTrackAtVtx(size_t i) const;  
    const float deltaPhiSeedClusterTrackAtCalo(size_t i) const;          
    const float deltaPhiEleClusterTrackAtCalo (size_t i) const;          
    const float deltaPhiSuperClusterTrackAtVtx(size_t i) const;          
    const float full5x5_sigmaIetaIeta         (size_t i) const;
    const float hcalOverEcal                  (size_t i) const;
    const float numberOfHits                  (size_t i) const;
    const float ooEmooP                       (size_t i) const;
    const float d0                            (size_t i) const;
    const float dz                            (size_t i) const;
    const float expectedMissingInnerHits      (size_t i) const;
    const float expectedMissingOuterHits      (size_t i) const;
    const float expectedMissingTrackHits      (size_t i) const;
    const bool  passConversionVeto            (size_t i) const;
    const float hcalPFClusterIso              (size_t i) const;
    const float ecalPFClusterIso              (size_t i) const;
    const float R9                            (size_t i) const;
    const float full5x5R9                     (size_t i) const;
    const float gsfchi2                       (size_t i) const;
    const float gsfndof                       (size_t i) const;
    const float gsfnormalizedchi2             (size_t i) const;
    
    const float Fbrem                         (size_t i) const;
    const float SeedEnergy                    (size_t i) const;
    const float Energy5x5                     (size_t i) const;
    
    const float tripleChargeAgreement         (size_t i) const;    
    
    const float GetElectronEffectiveAreaByPt      (size_t i) const;
    
    const float deltaEtaEleClusterTrackAtCaloByPt (size_t i) const { return deltaEtaEleClusterTrackAtCalo(indexByPt(i));  }          
    const float deltaEtaSeedClusterTrackAtCaloByPt(size_t i) const { return deltaEtaSeedClusterTrackAtCalo(indexByPt(i)); }          
    const float deltaEtaSuperClusterTrackAtVtxByPt(size_t i) const { return deltaEtaSuperClusterTrackAtVtx(indexByPt(i)); }          
    const float deltaPhiSeedClusterTrackAtCaloByPt(size_t i) const { return deltaPhiSeedClusterTrackAtCalo(indexByPt(i)); }
    const float deltaPhiEleClusterTrackAtCaloByPt (size_t i) const { return deltaPhiEleClusterTrackAtCalo(indexByPt(i));  }
    const float deltaPhiSuperClusterTrackAtVtxByPt(size_t i) const { return deltaPhiSuperClusterTrackAtVtx(indexByPt(i)); }
    const float full5x5_sigmaIetaIetaByPt         (size_t i) const { return full5x5_sigmaIetaIeta         (indexByPt(i)); }
    const float hcalOverEcalByPt                  (size_t i) const { return hcalOverEcal                  (indexByPt(i)); }
    const float numberOfHitsByPt                  (size_t i) const { return numberOfHits                  (indexByPt(i)); }
    const float ooEmooPByPt                       (size_t i) const { return ooEmooP                       (indexByPt(i)); }
    const float d0ByPt                            (size_t i) const { return d0                            (indexByPt(i)); }
    const float dzByPt                            (size_t i) const { return dz                            (indexByPt(i)); }
    const float expectedMissingInnerHitsByPt      (size_t i) const { return expectedMissingInnerHits      (indexByPt(i)); }
    const float expectedMissingOuterHitsByPt      (size_t i) const { return expectedMissingOuterHits      (indexByPt(i)); }
    const float expectedMissingTrackHitsByPt      (size_t i) const { return expectedMissingTrackHits      (indexByPt(i)); }
    
    const bool  passConversionVetoByPt            (size_t i) const { return passConversionVeto            (indexByPt(i)); }
    const float hcalPFClusterIsoByPt              (size_t i) const { return hcalPFClusterIso              (indexByPt(i)); }   
    const float ecalPFClusterIsoByPt              (size_t i) const { return ecalPFClusterIso              (indexByPt(i)); }   
    const float gsfchi2ByPt                       (size_t i) const { return gsfchi2                       (indexByPt(i)); }   
    const float gsfndofByPt                       (size_t i) const { return gsfndof                       (indexByPt(i)); }   
    const float gsfnormalizedchi2ByPt             (size_t i) const { return gsfnormalizedchi2             (indexByPt(i)); }   
    
    
    
    // Muon and electron isolation
    const float trackIso          (size_t i = 0) const;
    const float trackIso03        (size_t i = 0) const;
    const float chargedHadronIso  (size_t i = 0) const;
    const float chargedParticleIso(size_t i = 0) const;
    const float neutralHadronIso  (size_t i = 0) const;
    const float photonIso         (size_t i = 0) const;
    const float sumPUPt           (size_t i = 0) const;
    const float chargedHadronIso03  (size_t i = 0) const;
    const float neutralHadronIso03  (size_t i = 0) const;
    const float photonIso03         (size_t i = 0) const;
    const float sumPUPt03           (size_t i = 0) const;
    const float chargedHadronMiniIso(size_t i = 0) const;
    const float chargedPileUpMiniIso(size_t i = 0) const;
    const float neutralHadronMiniIso(size_t i = 0) const;
    const float photonMiniIso       (size_t i = 0) const;
    
    const float trackIsoByPt          (size_t i = 0) const { return trackIso          (indexByPt(i)); }
    const float trackIso03ByPt        (size_t i = 0) const { return trackIso03        (indexByPt(i)); }
    const float chargedHadronIsoByPt  (size_t i = 0) const { return chargedHadronIso  (indexByPt(i)); }
    const float chargedParticleIsoByPt(size_t i = 0) const { return chargedParticleIso(indexByPt(i)); }
    const float neutralHadronIsoByPt  (size_t i = 0) const { return neutralHadronIso  (indexByPt(i)); }
    const float photonIsoByPt         (size_t i = 0) const { return photonIso         (indexByPt(i)); }
    const float sumPUPtByPt           (size_t i = 0) const { return sumPUPt           (indexByPt(i)); }
    const float chargedHadronIso03ByPt  (size_t i = 0) const { return chargedHadronIso03  (indexByPt(i)); }
    const float neutralHadronIso03ByPt  (size_t i = 0) const { return neutralHadronIso03  (indexByPt(i)); }
    const float photonIso03ByPt         (size_t i = 0) const { return photonIso03         (indexByPt(i)); }
    const float sumPUPt03ByPt           (size_t i = 0) const { return sumPUPt03           (indexByPt(i)); }
    const float chargedHadronMiniIsoByPt(size_t i = 0) const { return chargedHadronMiniIso(indexByPt(i)); }
    const float chargedPileUpMiniIsoByPt(size_t i = 0) const { return chargedPileUpMiniIso(indexByPt(i)); }
    const float neutralHadronMiniIsoByPt(size_t i = 0) const { return neutralHadronMiniIso(indexByPt(i)); }
    const float photonMiniIsoByPt       (size_t i = 0) const { return photonMiniIso       (indexByPt(i)); }
    
    
    //Matt's
    // const int nExtraLepMatt(float a = -1) const;
    // const int nSoftMuMatt(float a = -1) const;
    
    // VBF Variables
    const int nJetVBF(float pt ,float eta,int applyCorrection, int applyID) const;
    const float mjj(float pt ,float eta,int applyCorrection, int applyID) const;
    const float dEtajj(float pt ,float eta,int applyCorrection, int applyID) const;
    const float zeppenfeld(size_t a,float pt ,float eta,int applyCorrection, int applyID) const;
    
    
    //bTagging variables ----------------
    const float jettcheByPt(size_t i) const;
    const float jettchpByPt(size_t i) const;
    const float jetbjpbByPt(size_t i) const;
    const float jetbjpByPt(size_t i) const;
    const float jetcsvv2ivfByPt(size_t i) const;
    const float jetssvheByPt(size_t i) const;
    const float jetssvhbByPt(size_t i) const;
    const float jetpfcsvByPt(size_t i) const;
    const float jetcmvav2ByPt(size_t i) const;
    const float jetpfCombinedCvsLJetTagsByPt(size_t i) const;
    const float jetpfCombinedCvsBJetTagsByPt(size_t i) const;
    const float jetDeepCSVBByPt(size_t i) const;
        
    const float jetSoftMuonPtByPt(size_t i) const;
    const float jetSoftMuonPt(size_t a, float minPtMuon, float maxDrMuonJet, float pt ,float eta,int applyCorrection, int applyID) const;
    const float jetSoftMuonEtaByPt(size_t i) const;
    const float jetSoftMuonEta(size_t a, float minPtMuon, float maxDrMuonJet, float pt ,float eta,int applyCorrection, int applyID) const;
    const float jetSoftMuonPhiByPt(size_t i) const;
    const float jetSoftMuonPhi(size_t a, float minPtMuon, float maxDrMuonJet, float pt ,float eta,int applyCorrection, int applyID) const;
    const float jetSoftMuonIsoByPt(size_t i) const;
    const float jetSoftMuonIso(size_t a, float minPtMuon, float maxDrMuonJet, float pt ,float eta,int applyCorrection, int applyID) const;
    const float jetSoftMuonDzByPt(size_t i) const;
    const float jetSoftMuonDz(size_t index, float minPtMuon, float maxDrMuonJet, float minPt,float eta,int applyCorrection,int applyID) const;
    const float jetSoftMuonD0ByPt(size_t i) const;
    const float jetSoftMuonD0(size_t index, float minPtMuon, float maxDrMuonJet, float minPt,float eta,int applyCorrection,int applyID) const;
    
    const float jetSoftMuonCountingByPt(size_t i) const;
    const float jetSoftMuonCounting(size_t a, float minPtMuon, float maxDrMuonJet, float pt ,float eta,int applyCorrection, int applyID) const;
    
    
    //Soft Muons
    const float SoftMuonPt(size_t i) const;
    const float SoftMuonPtByPt(size_t i) const {return SoftMuonPt(indexByPtSoftMuon(i)); }
    
    const float SoftMuonEta(size_t i) const;
    const float SoftMuonEtaByPt(size_t i) const {return SoftMuonEta(indexByPtSoftMuon(i)); }
    
    const float SoftMuonPhi(size_t i) const;
    const float SoftMuonPhiByPt(size_t i) const {return SoftMuonPhi(indexByPtSoftMuon(i)); }
    
    const float SoftMuonIso(size_t i) const;
    const float SoftMuonIsoByPt(size_t i) const {return SoftMuonIso(indexByPtSoftMuon(i)); }
    
    const float SoftMuonDz(size_t i) const;
    const float SoftMuonDzByPt(size_t i) const {return SoftMuonDz(indexByPtSoftMuon(i)); }
    
    const float SoftMuonDxy(size_t i) const;
    const float SoftMuonDxyByPt(size_t i) const {return SoftMuonDxy(indexByPtSoftMuon(i)); }
    
    const float SoftMuonIsTrackerMuon(size_t i) const;
    const float SoftMuonIsTrackerMuonByPt(size_t i) const {return SoftMuonIsTrackerMuon(indexByPtSoftMuon(i)); }
    
    const float TMLastStationAngTight(size_t i) const;
    const float TMLastStationAngTightByPt(size_t i) const {return TMLastStationAngTight(indexByPtSoftMuon(i)); }
    
    
    const math::XYZTLorentzVector photon(size_t a) const;
    void setPhoton (const edm::Handle<edm::View<reco::RecoCandidate> > &h, size_t i);
    const size_t indexByPtPho(size_t a = 0) const;
    const int nPhos() const;
    const float mllg() const;
    const float mllgid(int WP = 1) const;
    const pat::Photon * getPhoton(size_t a) const;
    const pat::Photon * getPhoton(const refToCand&) const;
    // Photon ID Variables
    const float Pho_sigmaIetaIeta      (size_t i) const;
    const float Pho_hadronicOverEm     (size_t i) const;
    const float Pho_ChargedHadronIso   (size_t i) const;
    const float Pho_NeutralHadronIso   (size_t i) const;
    const float Pho_PhotonIso          (size_t i) const;
    const int   Pho_PassElectronVeto   (size_t i) const;
    const int   Pho_HasPixelSeed       (size_t i) const;
    const float Pho_puChargedHadronIso (size_t i) const;
    const float Pho_patParticleIso     (size_t i) const;
    const float Pho_e3x3               (size_t i) const;
    const float Pho_R9                 (size_t i) const;
    
    
    
    
    void InitEffectiveAreasPhoton();
    void InitIDPhoton();
    double ChoosePhotonEffectiveArea(int type, double phoEta) const;
    const float Pho_rhoChargedHadronIso(size_t i) const;
    const float Pho_rhoNeutralHadronIso(size_t i) const;
    const float Pho_rhoPhotonIso(size_t i) const;
    const int Pho_n_ID(int WP = 1) const;
    const math::XYZTLorentzVector photon_id(size_t a, int WP = 1) const;
    
    const float photon_ptByPt   (size_t i) const;
    const float photon_etaByPt  (size_t i) const;
    const float photon_phiByPt  (size_t i) const;
    const float photon_sigmaIetaIetaByPt          (size_t i) const  { return    Pho_sigmaIetaIeta         ( indexByPtPho(i) )  ;  }
    const float photon_hadronicOverEmByPt         (size_t i) const  { return    Pho_hadronicOverEm        ( indexByPtPho(i) )  ;  }
    const float photon_ChargedHadronIsoByPt       (size_t i) const  { return    Pho_ChargedHadronIso      ( indexByPtPho(i) )  ;  }
    const float photon_NeutralHadronIsoByPt       (size_t i) const  { return    Pho_NeutralHadronIso      ( indexByPtPho(i) )  ;  }
    const float photon_PhotonIsoByPt              (size_t i) const  { return    Pho_PhotonIso             ( indexByPtPho(i) )  ;  }
    const float photon_PassElectronVetoByPt       (size_t i) const  { return    Pho_PassElectronVeto      ( indexByPtPho(i) )  ;  }
    const float photon_HasPixelSeedByPt           (size_t i) const  { return    Pho_HasPixelSeed          ( indexByPtPho(i) )  ;  }
    const float photon_puChargedHadronIsoByPt     (size_t i) const  { return    Pho_puChargedHadronIso    ( indexByPtPho(i) )  ;  }
    const float photon_patParticleIsoByPt         (size_t i) const  { return    Pho_patParticleIso        ( indexByPtPho(i) )  ;  }
    const float photon_e3x3ByPt                   (size_t i) const  { return    Pho_e3x3                  ( indexByPtPho(i) )  ;  }
    const float photon_R9ByPt                     (size_t i) const  { return    Pho_R9                    ( indexByPtPho(i) )  ;  }
    
    
    const float photonid_ptByPt (size_t i, int WP = 1) const;
    const float photonid_etaByPt(size_t i, int WP = 1) const;
    const float photonid_phiByPt(size_t i, int WP = 1) const;
    
    const bool Pho_IsIdIso(size_t i, int WP = 1) const;
    
    const reco::Candidate * getDressedLepton(size_t a) const;
    const reco::Candidate * getDressedLepton(const edm::Ptr<reco::Candidate>&) const;
    
    
    
  private:
    
    double maxEtaForJets_;
    double minPtForJets_;
    double dzCutForBtagJets_;
    bool   applyCorrectionForJets_;
    bool   apply50nsValues_;
    int    applyIDForJets_;
    
    int    applyJetCleaning_;
    
    double _maxDrSoftMuonJet;
    double _minPtSoftMuon;
    
    std::string _name_puJetIdDiscriminant;
    
    // User float values
    std::vector<std::string> userFloatLabels_;
    std::vector<float> userFloats_;
    // User int values
    std::vector<std::string> userIntLabels_;
    std::vector<int32_t> userInts_;
    
    static mwlSortByPtClass mwlSortByPt;
    //static sortPatJetByPtClass sortPatJetByPt;
    static std::vector<std::string> jecFiles_;
    
    //             int hypo_;
    reco::VertexRefVector vtxs_;
    std::vector<double> sumPts_;
    std::vector<double> sumPt2s_;
    reco::METRef tcMet_;
    //             reco::PFMETRef pfMet_;
    pat::METRef pfMet_;
    pat::METRef pfMetNoHf_;
    pat::METRef pfUncorrMet_;
    pat::METRef pfMuEGCleanMet_;
    pat::METRef pupMet_;
    reco::MET   trkMet_;
    reco::PFMET mvaMet_;
    reco::PFMET chargedMet_;
    reco::MET chargedMetSmurf_;
    
    // MET XYshift
    int hEtaPlus_counts_, hEtaMinus_counts_, h0Barrel_counts_;
    int h0EndcapPlus_counts_, h0EndcapMinus_counts_, gammaBarrel_counts_;
    int gammaEndcapPlus_counts_, gammaEndcapMinus_counts_, hHFPlus_counts_;
    int hHFMinus_counts_, egammaHFPlus_counts_, egammaHFMinus_counts_;
    
    double hEtaPlus_sumPt_, hEtaMinus_sumPt_, h0Barrel_sumPt_;
    double h0EndcapPlus_sumPt_, h0EndcapMinus_sumPt_, gammaBarrel_sumPt_;
    double gammaEndcapPlus_sumPt_, gammaEndcapMinus_sumPt_, hHFPlus_sumPt_;
    double hHFMinus_sumPt_, egammaHFPlus_sumPt_, egammaHFMinus_sumPt_;
    
    std::vector<refToCand> leps_;
    std::vector<refToCand> extraLeps_;
    std::vector<refToCand> softMuons_;
    std::vector<edm::Ptr<reco::Candidate> > dressedLeptons_;
    const HTXS::HiggsClassification* htxs_;
    //edm::RefToBaseVector<reco::RecoCandidate> leps_;
    //edm::RefToBaseVector<reco::RecoCandidate> extraLeps_;
    //edm::RefToBaseVector<reco::RecoCandidate> softMuons_;

    pat::PackedCandidateCollection pfcollection_;
    
    pat::TauCollection taus_;
    
    pat::JetRefVector jets_;
    pat::JetRefVector fatJets_;
    pat::JetRefVector tagJets_;
    pat::JetRefVector secondJets_;
    pat::JetRefVector trackJets_;
    reco::GenParticleRefVector genParticles_;
    reco::GenMETRef genMetRef_;
    reco::GenMET genMet_;
    reco::GenJetRefVector genJets_;
    // float mcGenWeight_;
    GenFilterInfo mcGenWeight_;
    GenEventInfoProduct GenInfoHandle_;
    lhef::HEPEUP LHEhepeup_;
    
    const LHEEventProduct* LHEInfoHandle_;
    
    // for the Gen ZGstar
    struct GenInfo{
      int id, status, nDaughters;
      int initStatus;
      float mass;
      float pt, eta, phi;
    };
    GenInfo muon1FromGstar;
    GenInfo muon2FromGstar;
    
    GenInfo elec1FromGstar;
    GenInfo elec2FromGstar;
    
    GenInfo MomInfo;
    
    float genDiLeptMassZGstar;
    float _ZGstarDiLept_DelaR;
    
    
    std::vector< std::string > comments_LHE_;
    std::vector< float > comments_LHE_weight_;
    std::vector< float > comments_LHE_rfac_;
    std::vector< float > comments_LHE_ffac_;
    
    double rhoJetIso_;
    double rhoCaloJetIso_;
    double rhoCentralNeutralJetIso_;

    unsigned int run_;
    unsigned int lumi_;
    unsigned int evt_;
    
    bool passesSingleMuData_;
    bool passesSingleElData_;
    bool passesDoubleMuData_;
    bool passesDoubleElData_;
    bool passesMuEGData_ ;
    bool passesSingleMuMC_ ;
    bool passesSingleElMC_ ;
    bool passesDoubleMuMC_ ;
    bool passesDoubleElMC_ ;
    bool passesMuEGMC_ ;
    bool passesAllEmbed_ ;
    bool passesFakeRateEl_ ;
    bool passesFakeRateMu_ ;
    
    std::vector <float> _bits;
    std::vector <float> _bitsPrescales;
    std::vector <float> _bitsL1minPrescales;
    std::vector <float> _bitsL1maxPrescales;
    std::vector <float> _specialBits;
    
    //---- electrons
    float _eaElectronIso[7][2];
    std::vector <std::string> _electronIds;
    std::map <std::string, std::vector<bool> > _electronIdsMap;
    std::map <std::string, std::vector<float> > _electronMvaIdsMap;
    
    // GEN
    std::vector<unsigned int> leptonIndices;
    
    //---- photons
    std::vector<refToCand> phos_;
    double eaPhotonIso_[7][3];
    double PhotonIDparams_[3][2][5];
    
    //---- indexes
    mutable std::map<std::string, std::vector<indexValueStruct> > _index_jet; // ---> it can be changed in "const" methods
    mutable std::map<std::string, std::vector<indexValueStruct> > _index_secondjet;
    mutable std::map<std::string, std::vector<indexValueStruct> > _index_lep;
    mutable std::map<std::string, std::vector<indexValueStruct> > _index_softMuon;
    
    
    
  };
  
}

#endif
