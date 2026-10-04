// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dd730
// Recovered Name: _ZN11LayerFlowNS13LFExifInfoJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dd730 | Size: 36 bytes | SHA256: 61cd4c59ee078d214a91bbd2f1fc3aab4bb96f1fad36f42caab4901ddd57e801
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x537030)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS13LFExifInfoJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x2dd730 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2dd734 */ mov x29, sp;
    /* 0x2dd738 */ mov w0, #0x30;
    _Znwm();
    /* 0x2dd740 */ movi v0.2d, #0000000000000000;
    /* 0x2dd744 */ stp q0, q0, [x0];
    /* 0x2dd748 */ str q0, [x0, #0x20];
    /* 0x2dd74c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
