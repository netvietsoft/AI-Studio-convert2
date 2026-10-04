// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2bee5c
// Recovered Name: _ZN11LayerFlowNS18LFAutoBrushDataJNI9nSetColorEP7_JNIEnvP8_jobjectlP8_jstring
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2bee5c | Size: 132 bytes | SHA256: 8daefecb5c682a314877c9db33b95f2ee8180d506437a0185d7791b8961624e9
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: nSetColor(JLjava/lang/String;)V (table at 0x531b08)

jobject _ZN11LayerFlowNS18LFAutoBrushDataJNI9nSetColorEP7_JNIEnvP8_jobjectlP8_jstring(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x2bee5c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2bee60 */ stp x22, x21, [sp, #0x10];
    /* 0x2bee64 */ stp x20, x19, [sp, #0x20];
    /* 0x2bee68 */ mov x29, sp;
    /* 0x2bee6c */ mov x20, x2;
    /* 0x2bee70 */ cbz x3, #0x2beec4;
    /* 0x2bee74 */ ldr x8, [x0];
    /* 0x2bee78 */ mov x1, x3;
    /* 0x2bee7c */ mov x2, xzr;
    /* 0x2bee80 */ mov x19, x3;
    /* 0x2bee84 */ mov x21, x0;
    sub_525b68();
}
