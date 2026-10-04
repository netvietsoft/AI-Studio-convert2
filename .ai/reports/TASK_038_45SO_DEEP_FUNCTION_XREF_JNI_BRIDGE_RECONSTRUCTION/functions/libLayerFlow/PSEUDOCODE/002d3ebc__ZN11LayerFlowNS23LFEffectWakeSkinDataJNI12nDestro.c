// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d3ebc
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d3ebc | Size: 92 bytes | SHA256: c2da53d442feb748fd210d1d07cdf0a6ee5511305863f9c59069b8f40310a337
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5352e8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyInfo is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 23 instructions
    /* 0x2d3ebc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d3ec0 */ str x19, [sp, #0x10];
    /* 0x2d3ec4 */ mov x29, sp;
    /* 0x2d3ec8 */ mov x19, x2;
    /* 0x2d3ecc */ nop ;
    /* 0x2d3ed0 */ adr x1, #0x1e1361;
    /* 0x2d3ed4 */ adrp x2, #0x1dd000;
    /* 0x2d3ed8 */ add x2, x2, #0xecd;
    /* 0x2d3edc */ mov w0, #6;
    /* 0x2d3ee0 */ mov x3, x19;
    __android_log_print();
    _ZdlPv();
    return x0;
}
