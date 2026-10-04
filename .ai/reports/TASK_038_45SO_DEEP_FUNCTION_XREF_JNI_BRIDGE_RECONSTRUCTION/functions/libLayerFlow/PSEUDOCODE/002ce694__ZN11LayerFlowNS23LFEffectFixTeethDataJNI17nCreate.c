// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce694
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI17nCreateTidyParamsEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce694 | Size: 32 bytes | SHA256: 94ce4ddd627bc6e86d0150cc74a1b95c553c5e7f9dfe6e4bc0e8be7d34e13f86
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x534298)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI17nCreateTidyParamsEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x2ce694 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2ce698 */ mov x29, sp;
    /* 0x2ce69c */ mov w0, #8;
    _Znwm();
    /* 0x2ce6a4 */ mov x8, #-0x100000000;
    /* 0x2ce6a8 */ str x8, [x0];
    /* 0x2ce6ac */ ldp x29, x30, [sp], #0x10;
    return x0;
}
