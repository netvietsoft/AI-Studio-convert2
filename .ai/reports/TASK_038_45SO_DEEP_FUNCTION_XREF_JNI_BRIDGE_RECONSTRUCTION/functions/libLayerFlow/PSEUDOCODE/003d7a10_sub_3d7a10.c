// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d7a10
// Recovered Name: sub_3d7a10
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3d7a10 | Size: 1008 bytes | SHA256: ab80c84c78873d223ec7ef08541cd4ef0c3c277a11b12072684a4275e31acb66
// Callers: 0 | Callees: 27 | Imports: 1

// Calls external APIs: _Znwm
// Strings referenced:
//   "212"
//   "blur"
//   "creative"
//   "special_effect"

void sub_3d7a10(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 252 instructions
    /* 0x3d7a10 */ ldr x8, [x27];
    /* 0x3d7a14 */ mov x0, x27;
    /* 0x3d7a18 */ ldr x8, [x8, #0x10];
    /* 0x3d7a1c */ blr x8;
    /* 0x3d7a20 */ mov x0, x27;
    /* 0x3d7a24 */ b #0x3d7e4c;
    /* 0x3d7a28 */ ldr x10, [x9, #0x18];
    /* 0x3d7a2c */ add x9, x9, #9;
    /* 0x3d7a30 */ tst w8, #1;
    /* 0x3d7a34 */ csel x8, x9, x10, eq;
    /* 0x3d7a38 */ mov w10, #0x6465;
    sub_3d88e8();
    _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_16CLFMarkProcessorEvEERS3_RKNS0_IT_EE();
    sub_3d89dc();
    _Znwm();
    _ZN11LayerFlowNS19CLFStickerProcessorC1Ev();
    _Znwm();
    _ZN11LayerFlowNS17CLFFrameProcessorC1Ev();
    sub_3d8864();
    sub_3d8a2c();
    _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_22CLFAutoBeautyProcessorEvEERS3_RKNS0_IT_EE();
    sub_3d8b20();
    sub_3d8864();
    sub_3d8b70();
    _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_20CLFCreativeProcessorEvEERS3_RKNS0_IT_EE();
    sub_3d8c64();
    sub_3d8864();
    sub_3d8cb4();
    _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_25CLFSpecialEffectProcessorEvEERS3_RKNS0_IT_EE();
    sub_3d8da8();
    sub_3d8864();
    sub_3d8df8();
    _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_16CLFBlurProcessorEvEERS3_RKNS0_IT_EE();
    sub_3d8eec();
    _Znwm();
    _ZN11LayerFlowNS16CLFEditProcessorC2Ev();
    _Znwm();
    _ZN11LayerFlowNS19CLFEnhanceProcessorC1Ev();
    _Znwm();
    _ZN11LayerFlowNS18CLFOriginProcessorC1Ev();
    _Znwm();
    _ZN11LayerFlowNS22CLFBgBeautifyProcessorC2Ev();
    sub_3d8864();
    sub_3d8f3c();
    _ZNSt6__ndk110shared_ptrIN11LayerFlowNS16CLFBaseProcessorEEaSB8ne180000INS1_22CLFSkinWhitenProcessorEvEERS3_RKNS0_IT_EE();
    sub_3d9030();
    _Znwm();
    _ZN11LayerFlowNS16CLFTextProcessorC2Ev();
    _Znwm();
    _ZN11LayerFlowNS19CLFCompareProcessorC1Ev();
}
