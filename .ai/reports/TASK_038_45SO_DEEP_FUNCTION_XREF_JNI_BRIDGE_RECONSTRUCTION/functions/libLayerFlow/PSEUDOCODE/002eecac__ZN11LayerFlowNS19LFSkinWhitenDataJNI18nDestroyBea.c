// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eecac
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI18nDestroyBeautyGlowEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eecac | Size: 76 bytes | SHA256: f6d1cf32da05f8e0378bfd49ef5635c571f227b1d6fb94d8eee58dee809a5e79
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x539c48)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nDestroyBeautyGlow is called,addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI18nDestroyBeautyGlowEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2eecac */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2eecb0 */ str x19, [sp, #0x10];
    /* 0x2eecb4 */ mov x29, sp;
    /* 0x2eecb8 */ mov x19, x2;
    /* 0x2eecbc */ adrp x1, #0x1e1000;
    /* 0x2eecc0 */ add x1, x1, #0x361;
    /* 0x2eecc4 */ adrp x2, #0x1ce000;
    /* 0x2eecc8 */ add x2, x2, #0x459;
    /* 0x2eeccc */ mov w0, #6;
    /* 0x2eecd0 */ mov x3, x19;
    __android_log_print();
    return x0;
}
