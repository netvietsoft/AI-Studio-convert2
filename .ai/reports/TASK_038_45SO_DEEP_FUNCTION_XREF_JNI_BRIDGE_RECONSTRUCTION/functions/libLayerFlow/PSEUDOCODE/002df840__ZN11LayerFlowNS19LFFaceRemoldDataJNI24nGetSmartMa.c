// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df840
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI24nGetSmartMaterialPointerEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df840 | Size: 56 bytes | SHA256: 84af01b59ae42ac54c1c1d558690f340aeb63de75d929d6323f51b583c860acf
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetSmartMaterialPointer(J)J (table at 0x5377f8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI24nGetSmartMaterialPointerEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x2df840 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2df844 */ str x19, [sp, #0x10];
    /* 0x2df848 */ mov x29, sp;
    /* 0x2df84c */ mov w0, #0x28;
    /* 0x2df850 */ mov x19, x2;
    _Znwm();
    /* 0x2df858 */ ldur q0, [x19, #0x18];
    /* 0x2df85c */ ldur q1, [x19, #0x28];
    /* 0x2df860 */ ldr x8, [x19, #0x38];
    /* 0x2df864 */ stp q0, q1, [x0];
    /* 0x2df868 */ str x8, [x0, #0x20];
    return x0;
}
