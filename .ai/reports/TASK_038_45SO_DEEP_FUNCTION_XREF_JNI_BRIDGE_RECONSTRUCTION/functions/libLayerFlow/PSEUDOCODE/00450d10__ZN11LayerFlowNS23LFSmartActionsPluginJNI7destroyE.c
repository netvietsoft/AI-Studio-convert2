// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x450d10
// Recovered Name: _ZN11LayerFlowNS23LFSmartActionsPluginJNI7destroyEP7_JNIEnvP8_jobjectl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x450d10 | Size: 96 bytes | SHA256: 47a60804c71036036c653fe3fed2ee770443af99096563b0316095c9cf3caef0
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nDestroy(J)V (table at 0x546ad0)
// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z
// Strings referenced:
//   "destroy"
//   "iklf"
//   "jniSmartActionsPlg<%s:%d> ------ destroying LFSmartActionsPluginJNI %li"

jobject _ZN11LayerFlowNS23LFSmartActionsPluginJNI7destroyEP7_JNIEnvP8_jobjectl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 24 instructions
    /* 0x450d10 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x450d14 */ str x19, [sp, #0x10];
    /* 0x450d18 */ mov x29, sp;
    /* 0x450d1c */ mov x19, x2;
    /* 0x450d20 */ adrp x0, #0x1d9000;
    /* 0x450d24 */ add x0, x0, #0x93c;
    /* 0x450d28 */ adrp x2, #0x1cf000;
    /* 0x450d2c */ add x2, x2, #0x4a;
    /* 0x450d30 */ adrp x3, #0x1e7000;
    /* 0x450d34 */ add x3, x3, #0x9e6;
    /* 0x450d38 */ mov w1, #3;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
}
