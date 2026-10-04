// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce604
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI13nCreateParamsEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce604 | Size: 36 bytes | SHA256: 4a849139d224ceae34a15e7a478da62d3d697feb6bd8fc27431d5a0796387e92
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x534208)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI13nCreateParamsEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2ce604 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2ce608 */ mov x29, sp;
    /* 0x2ce60c */ mov w0, #0x10;
    _Znwm();
    /* 0x2ce614 */ mov w8, #-1;
    /* 0x2ce618 */ stp xzr, xzr, [x0];
    /* 0x2ce61c */ str w8, [x0, #8];
    /* 0x2ce620 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
