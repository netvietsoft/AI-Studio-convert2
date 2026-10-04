// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce648
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI18nDestroyTidyParamsEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce648 | Size: 76 bytes | SHA256: cfa29a9c40f0f0b496e6169d3337f6f0e60da28ac015b50cc242d8d1299af0bd
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x534280)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyTidyParams is called,addr => %p"

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI18nDestroyTidyParamsEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x2ce648 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ce64c */ str x19, [sp, #0x10];
    /* 0x2ce650 */ mov x29, sp;
    /* 0x2ce654 */ mov x19, x2;
    /* 0x2ce658 */ nop ;
    /* 0x2ce65c */ adr x1, #0x1e1361;
    /* 0x2ce660 */ adrp x2, #0x1ef000;
    /* 0x2ce664 */ add x2, x2, #0xc73;
    /* 0x2ce668 */ mov w0, #6;
    /* 0x2ce66c */ mov x3, x19;
    __android_log_print();
    return x0;
}
