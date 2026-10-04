// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3d4610
// Recovered Name: _ZN11LayerFlowNS24LFStickerLocateStatusJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3d4610 | Size: 56 bytes | SHA256: 8882c488dfa6c5569b662dedaf53a77137af8b715699245c5effb060e23f0791
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x542138)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS24LFStickerLocateStatusJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x3d4610 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3d4614 */ mov x29, sp;
    /* 0x3d4618 */ mov w0, #0x24;
    _Znwm();
    /* 0x3d4620 */ adrp x8, #0x1f4000;
    /* 0x3d4624 */ adrp x9, #0x1f3000;
    /* 0x3d4628 */ stp xzr, xzr, [x0, #0x10];
    /* 0x3d462c */ ldr q0, [x8, #0x580];
    /* 0x3d4630 */ ldr q1, [x9, #0xf60];
    /* 0x3d4634 */ strb wzr, [x0, #0x10];
    /* 0x3d4638 */ stur q0, [x0, #0x14];
    return x0;
}
