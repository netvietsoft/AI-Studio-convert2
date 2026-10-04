// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee49c
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetMaterialPointerEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee49c | Size: 44 bytes | SHA256: 4b597223797c28fbcd5d3963796b7902671bd2d8be750bf0935151ce8195029c
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nGetMaterialPointer(J)J (table at 0x5396f0)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI19nGetMaterialPointerEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2ee49c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ee4a0 */ str x19, [sp, #0x10];
    /* 0x2ee4a4 */ mov x29, sp;
    /* 0x2ee4a8 */ mov w0, #0x10;
    /* 0x2ee4ac */ mov x19, x2;
    _Znwm();
    /* 0x2ee4b4 */ ldr q0, [x19];
    /* 0x2ee4b8 */ str q0, [x0];
    /* 0x2ee4bc */ ldr x19, [sp, #0x10];
    /* 0x2ee4c0 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
