// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2eed74
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nCreateMaterialParamEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2eed74 | Size: 72 bytes | SHA256: 3c6a38d03b0ce21fa54689421d5276cab9061fe5f9f2831e24df3e038ad14f15
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x539cf0)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nCreateMaterialParam is called, addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI20nCreateMaterialParamEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 18 instructions
    /* 0x2eed74 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2eed78 */ str x19, [sp, #0x10];
    /* 0x2eed7c */ mov x29, sp;
    /* 0x2eed80 */ mov w0, #0x10;
    _Znwm();
    /* 0x2eed88 */ mov x19, x0;
    /* 0x2eed8c */ stp xzr, xzr, [x0];
    /* 0x2eed90 */ adrp x1, #0x1e1000;
    /* 0x2eed94 */ add x1, x1, #0x361;
    /* 0x2eed98 */ adrp x2, #0x1de000;
    /* 0x2eed9c */ add x2, x2, #0xab;
    __android_log_print();
    return x0;
}
