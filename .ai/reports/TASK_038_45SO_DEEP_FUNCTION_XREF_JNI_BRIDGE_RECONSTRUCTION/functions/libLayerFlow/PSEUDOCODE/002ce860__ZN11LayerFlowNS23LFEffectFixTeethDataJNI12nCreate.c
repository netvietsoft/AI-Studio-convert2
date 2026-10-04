// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ce860
// Recovered Name: _ZN11LayerFlowNS23LFEffectFixTeethDataJNI12nCreateModelEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ce860 | Size: 40 bytes | SHA256: 80327e229dfb3bd7c0b616a8fa8f7d9e15bef3b81dda8f76b245b7acb12f9a6a
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x5344a8)
// Calls external APIs: _Znwm

jobject _ZN11LayerFlowNS23LFEffectFixTeethDataJNI12nCreateModelEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x2ce860 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2ce864 */ mov x29, sp;
    /* 0x2ce868 */ mov w0, #0x50;
    _Znwm();
    /* 0x2ce870 */ movi v0.2d, #0000000000000000;
    /* 0x2ce874 */ stp q0, q0, [x0];
    /* 0x2ce878 */ stp q0, q0, [x0, #0x20];
    /* 0x2ce87c */ str q0, [x0, #0x40];
    /* 0x2ce880 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
