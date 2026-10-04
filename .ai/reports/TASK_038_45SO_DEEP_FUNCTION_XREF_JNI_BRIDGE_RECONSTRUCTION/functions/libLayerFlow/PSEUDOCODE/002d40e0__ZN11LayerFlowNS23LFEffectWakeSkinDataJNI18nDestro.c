// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d40e0
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI18nDestroyBeautyGlowEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d40e0 | Size: 76 bytes | SHA256: ab8aacbc262e1c287ddde56369009401eece1133cce570de1483f7d9c8ee7483
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroyBeautyGlow(J)V (table at 0x535720)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyBeautyGlow is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI18nDestroyBeautyGlowEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2d40e0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d40e4 */ str x19, [sp, #0x10];
    /* 0x2d40e8 */ mov x29, sp;
    /* 0x2d40ec */ mov x19, x2;
    /* 0x2d40f0 */ nop ;
    /* 0x2d40f4 */ adr x1, #0x1e1361;
    /* 0x2d40f8 */ adrp x2, #0x1ce000;
    /* 0x2d40fc */ add x2, x2, #0x459;
    /* 0x2d4100 */ mov w0, #6;
    /* 0x2d4104 */ mov x3, x19;
    __android_log_print();
    return x0;
}
