// Function: LayerFlowNS::CSceneDetector::unregisterEngine()
// RVA: 0x471d08, Size: 72 bytes
int64_t _ZN11LayerFlowNS14CSceneDetector16unregisterEngineEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vlai_engine_uninit(...); // call PLT API at 0x471d24
    vlai_engine_destroy(...); // call PLT API at 0x471d2c
    vlai_setting_patch_destroy(...); // call PLT API at 0x471d3c
    return a0;
}
