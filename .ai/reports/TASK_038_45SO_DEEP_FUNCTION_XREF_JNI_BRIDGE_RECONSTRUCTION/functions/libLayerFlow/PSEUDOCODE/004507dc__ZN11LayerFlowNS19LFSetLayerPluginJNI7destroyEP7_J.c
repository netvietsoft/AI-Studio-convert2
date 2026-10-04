// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x4507dc
// Recovered Name: _ZN11LayerFlowNS19LFSetLayerPluginJNI7destroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x4507dc | Size: 96 bytes | SHA256: e4a8536d5ed2c27a7d4e47393822d34ce547dac96469528280d717ba1075c2f3
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x546a20)
// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z
// Strings referenced:
//   "destroy"
//   "iklf"
//   "jniSetLayerPlg<%s:%d> ------ destroying LFSetLayerPluginJNI %li"

jobject _ZN11LayerFlowNS19LFSetLayerPluginJNI7destroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x4507dc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x4507e0 */ str x19, [sp, #0x10];
    /* 0x4507e4 */ mov x29, sp;
    /* 0x4507e8 */ mov x19, x2;
    /* 0x4507ec */ adrp x0, #0x1d9000;
    /* 0x4507f0 */ add x0, x0, #0x93c;
    /* 0x4507f4 */ adrp x2, #0x1eb000;
    /* 0x4507f8 */ add x2, x2, #0x29f;
    /* 0x4507fc */ adrp x3, #0x1e7000;
    /* 0x450800 */ add x3, x3, #0x9e6;
    /* 0x450804 */ mov w1, #3;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
}
