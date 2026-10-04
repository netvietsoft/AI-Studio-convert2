// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dd854
// Recovered Name: _ZN11LayerFlowNS13LFExifInfoJNI9nGetModelEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dd854 | Size: 44 bytes | SHA256: 45025404203c2a2d7dd622bb98b27643f7bbf1ea360a2fdb1b080716cb1391b9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nGetModel(J)Ljava/lang/String; (table at 0x537090)

jobject _ZN11LayerFlowNS13LFExifInfoJNI9nGetModelEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x2dd854 */ cbz x2, #0x2dd878;
    /* 0x2dd858 */ ldrb w8, [x2, #0x18];
    /* 0x2dd85c */ ldr x10, [x0];
    /* 0x2dd860 */ add x11, x2, #0x19;
    /* 0x2dd864 */ ldr x9, [x2, #0x28];
    /* 0x2dd868 */ tst w8, #1;
    /* 0x2dd86c */ ldr x2, [x10, #0x538];
    /* 0x2dd870 */ csel x1, x11, x9, eq;
    /* 0x2dd874 */ br x2;
    /* 0x2dd878 */ mov x0, xzr;
    return x0;
}
