// Function: LayerFlowNS::CSceneDetector::~CSceneDetector()
// RVA: 0x471ca4, Size: 100 bytes
int64_t _ZN11LayerFlowNS14CSceneDetectorD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_engine_uninit(...); // call PLT API at 0x471cc0
    vlai_engine_destroy(...); // call PLT API at 0x471cc8
    vlai_setting_patch_destroy(...); // call PLT API at 0x471cd8
    return a0;
    _ZdlPv(...); // call PLT API at 0x471d00
    sub_2BF8C4(...); // call internal at 0x471d04
}
