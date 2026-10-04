// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x3bfcbc
// Recovered Name: _ZN11LayerFlowNS24LFCreativeStickerInfoJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x3bfcbc | Size: 76 bytes | SHA256: fddf0135068acc418153c4ee28033f90b231e9253527bf11865730a4d47a4c1a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x540198)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS24LFCreativeStickerInfoJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 19 instructions
    /* 0x3bfcbc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x3bfcc0 */ mov x29, sp;
    /* 0x3bfcc4 */ mov w0, #0x58;
    _Znwm();
    /* 0x3bfccc */ movi v0.2d, #0000000000000000;
    /* 0x3bfcd0 */ adrp x8, #0x1f4000;
    /* 0x3bfcd4 */ str xzr, [x0, #0x50];
    /* 0x3bfcd8 */ ldr q1, [x8, #0x40];
    /* 0x3bfcdc */ adrp x8, #0x1f4000;
    /* 0x3bfce0 */ stp q0, q0, [x0];
    /* 0x3bfce4 */ str q0, [x0, #0x20];
    return x0;
}
