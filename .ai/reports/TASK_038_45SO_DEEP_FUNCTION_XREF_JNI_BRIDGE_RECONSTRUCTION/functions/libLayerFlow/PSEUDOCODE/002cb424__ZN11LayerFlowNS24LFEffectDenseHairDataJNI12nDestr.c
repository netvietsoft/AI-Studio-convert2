// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cb424
// Recovered Name: _ZN11LayerFlowNS24LFEffectDenseHairDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cb424 | Size: 76 bytes | SHA256: b64e673ce028ce4950b5592a27cdbcd81df1aa9f9b32dfc825cf92df62f82ff0
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x5337e0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyInfo is called,addr => %p"

jobject _ZN11LayerFlowNS24LFEffectDenseHairDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2cb424 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cb428 */ str x19, [sp, #0x10];
    /* 0x2cb42c */ mov x29, sp;
    /* 0x2cb430 */ mov x19, x2;
    /* 0x2cb434 */ nop ;
    /* 0x2cb438 */ adr x1, #0x1e1361;
    /* 0x2cb43c */ adrp x2, #0x1dd000;
    /* 0x2cb440 */ add x2, x2, #0xecd;
    /* 0x2cb444 */ mov w0, #6;
    /* 0x2cb448 */ mov x3, x19;
    __android_log_print();
    return x0;
}
