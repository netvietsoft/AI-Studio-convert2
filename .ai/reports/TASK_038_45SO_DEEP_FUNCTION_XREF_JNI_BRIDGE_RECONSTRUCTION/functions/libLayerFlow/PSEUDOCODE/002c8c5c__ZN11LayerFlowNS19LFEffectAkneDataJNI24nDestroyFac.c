// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c8c5c
// Recovered Name: _ZN11LayerFlowNS19LFEffectAkneDataJNI24nDestroyFaceRegionSwitchEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c8c5c | Size: 76 bytes | SHA256: 8aea15ae9c89d7682283883536b1b537fedcc187f420e3bbe58c74fec152d2e0
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5330e0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyFaceRegionSwitch is called,addr => %p"

jobject _ZN11LayerFlowNS19LFEffectAkneDataJNI24nDestroyFaceRegionSwitchEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2c8c5c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c8c60 */ str x19, [sp, #0x10];
    /* 0x2c8c64 */ mov x29, sp;
    /* 0x2c8c68 */ mov x19, x2;
    /* 0x2c8c6c */ nop ;
    /* 0x2c8c70 */ adr x1, #0x1e1361;
    /* 0x2c8c74 */ adrp x2, #0x1e1000;
    /* 0x2c8c78 */ add x2, x2, #0x440;
    /* 0x2c8c7c */ mov w0, #6;
    /* 0x2c8c80 */ mov x3, x19;
    __android_log_print();
    return x0;
}
