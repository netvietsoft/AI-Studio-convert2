// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c3580
// Recovered Name: _ZN11LayerFlowNS16LFBlurModularJNI9getCenterEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c3580 | Size: 164 bytes | SHA256: fa7ca5bedf021a7d0c66996ce0770cd73037e301b7743533388ab8eeee5bbfdb
// Callers: 0 | Callees: 1 | Imports: 0

// Dynamic Registration: getCenter(J)[D (table at 0x532810)

jobject _ZN11LayerFlowNS16LFBlurModularJNI9getCenterEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x2c3580 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c3584 */ stp x20, x19, [sp, #0x10];
    /* 0x2c3588 */ mov x29, sp;
    /* 0x2c358c */ mov x8, x2;
    /* 0x2c3590 */ mov x20, x2;
    /* 0x2c3594 */ mov x19, x0;
    /* 0x2c3598 */ ldp x9, x10, [x8, #0x50]!;
    /* 0x2c359c */ sub x12, x10, x9;
    /* 0x2c35a0 */ asr x11, x12, #3;
    /* 0x2c35a4 */ cmp x11, #1;
    /* 0x2c35a8 */ b.hi #0x2c35c4;
    sub_2c37fc();
    return x0;
}
