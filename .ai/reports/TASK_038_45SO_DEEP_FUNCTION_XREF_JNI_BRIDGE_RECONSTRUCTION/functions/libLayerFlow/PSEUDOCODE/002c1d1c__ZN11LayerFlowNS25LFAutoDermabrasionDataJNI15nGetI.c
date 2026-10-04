// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c1d1c
// Recovered Name: _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI15nGetInfoPointerEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c1d1c | Size: 52 bytes | SHA256: add4a8afe44e71dd9d3037a77b59f771e8873f460a637aedfaad2a87b3f011bd
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetInfoPointer(J)J (table at 0x531e20)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS25LFAutoDermabrasionDataJNI15nGetInfoPointerEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 13 instructions
    /* 0x2c1d1c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c1d20 */ str x19, [sp, #0x10];
    /* 0x2c1d24 */ mov x29, sp;
    /* 0x2c1d28 */ mov w0, #0xc;
    /* 0x2c1d2c */ mov x19, x2;
    _Znwm();
    /* 0x2c1d34 */ ldr x8, [x19, #0x20];
    /* 0x2c1d38 */ ldr w9, [x19, #0x28];
    /* 0x2c1d3c */ str x8, [x0];
    /* 0x2c1d40 */ str w9, [x0, #8];
    /* 0x2c1d44 */ ldr x19, [sp, #0x10];
    return x0;
}
