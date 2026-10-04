// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x44e854
// Recovered Name: _ZN11LayerFlowNS22LFOutputImagePluginJNI29nSetRunInOffScreenContextOnlyEP7_JNIEnvP8_jobjectlh
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x44e854 | Size: 192 bytes | SHA256: c6f31dc5f8da90e74a260b1f23d095c030689844a671d6db7dffcbc720169693
// Callers: 0 | Callees: 2 | Imports: 2

// Dynamic Registration: nSetRunInOffScreenContextOnly(JZ)V (table at 0x5466e0)
// Calls external APIs: _ZNSt6__ndk119__shared_weak_count14__release_weakEv, __dynamic_cast

jobject _ZN11LayerFlowNS22LFOutputImagePluginJNI29nSetRunInOffScreenContextOnlyEP7_JNIEnvP8_jobjectlh(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x44e854 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x44e858 */ str x21, [sp, #0x10];
    /* 0x44e85c */ stp x20, x19, [sp, #0x20];
    /* 0x44e860 */ mov x29, sp;
    /* 0x44e864 */ mov x19, x2;
    /* 0x44e868 */ ldr x0, [x2, #8];
    /* 0x44e86c */ adrp x1, #0x54a000;
    /* 0x44e870 */ adrp x2, #0x54b000;
    /* 0x44e874 */ ldr x1, [x1, #0xde0];
    /* 0x44e878 */ mov w20, w3;
    /* 0x44e87c */ ldr x2, [x2, #0x4e0];
    __dynamic_cast();
    sub_5263b0();
    sub_5263e0();
    return x0;
    return x0;
}
