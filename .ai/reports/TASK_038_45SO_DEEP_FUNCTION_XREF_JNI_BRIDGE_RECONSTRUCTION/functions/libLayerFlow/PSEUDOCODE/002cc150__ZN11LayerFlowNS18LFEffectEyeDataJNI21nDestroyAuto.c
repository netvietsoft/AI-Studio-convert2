// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2cc150
// Recovered Name: _ZN11LayerFlowNS18LFEffectEyeDataJNI21nDestroyAutoEyeParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2cc150 | Size: 76 bytes | SHA256: 635fa6065d120834317106222847e1eb95773ad0159d47789738caba203d181a
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x533ae0)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyAutoEyeParams is called,addr => %p"

jobject _ZN11LayerFlowNS18LFEffectEyeDataJNI21nDestroyAutoEyeParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2cc150 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2cc154 */ str x19, [sp, #0x10];
    /* 0x2cc158 */ mov x29, sp;
    /* 0x2cc15c */ mov x19, x2;
    /* 0x2cc160 */ nop ;
    /* 0x2cc164 */ adr x1, #0x1e1361;
    /* 0x2cc168 */ adrp x2, #0x1d1000;
    /* 0x2cc16c */ add x2, x2, #0x943;
    /* 0x2cc170 */ mov w0, #6;
    /* 0x2cc174 */ mov x3, x19;
    __android_log_print();
    return x0;
}
