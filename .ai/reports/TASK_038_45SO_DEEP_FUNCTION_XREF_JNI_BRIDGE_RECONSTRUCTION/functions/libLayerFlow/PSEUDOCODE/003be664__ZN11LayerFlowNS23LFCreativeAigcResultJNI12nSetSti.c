// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3be664
// Recovered Name: _ZN11LayerFlowNS23LFCreativeAigcResultJNI12nSetStickersEP7_JNIEnvP8_jobjectlP11_jlongArray
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3be664 | Size: 452 bytes | SHA256: a468a7bf2cecf678e553f57765e5798bde0706f02459787df0c1ac829618539e
// Callers: 0 | Callees: 3 | Imports: 1

// Dynamic Registration: nSetStickers(J[J)V (table at 0x5400a8)
// Calls external APIs: _ZdlPv

jobject _ZN11LayerFlowNS23LFCreativeAigcResultJNI12nSetStickersEP7_JNIEnvP8_jobjectlP11_jlongArray(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 113 instructions
    /* 0x3be664 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x3be668 */ str x27, [sp, #0x10];
    /* 0x3be66c */ stp x26, x25, [sp, #0x20];
    /* 0x3be670 */ stp x24, x23, [sp, #0x30];
    /* 0x3be674 */ stp x22, x21, [sp, #0x40];
    /* 0x3be678 */ stp x20, x19, [sp, #0x50];
    /* 0x3be67c */ mov x29, sp;
    /* 0x3be680 */ ldr x8, [x0];
    /* 0x3be684 */ mov x1, x3;
    /* 0x3be688 */ mov x20, x3;
    /* 0x3be68c */ mov x21, x0;
    _ZdlPv();
    _ZdlPv();
    _ZNSt6__ndk16vectorI19CreativeStickerInfoNS_9allocatorIS1_EEE21__push_back_slow_pathIRKS1_EEPS1_OT_();
    sub_2bc260();
    sub_2bc260();
    _ZdlPv();
    sub_526544();
    sub_526544();
}
