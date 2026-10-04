// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x450774
// Recovered Name: _ZN11LayerFlowNS19LFSetLayerPluginJNI6createEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x450774 | Size: 104 bytes | SHA256: bdf4b74aa39ddf1adb6a29dc5104e5ad9d68c05e832cd812161ce06e274e3e91
// Callers: 0 | Callees: 2 | Imports: 3

// Dynamic Registration: nCreate()J (table at 0x546a08)
// Calls external APIs: _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z, _ZdlPv, _Znwm
// Strings referenced:
//   "create"
//   "iklf"
//   "jniSetLayerPlg<%s:%d> ++++++ creating LFSetLayerPluginJNI %p"

jobject _ZN11LayerFlowNS19LFSetLayerPluginJNI6createEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x450774 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x450778 */ stp x20, x19, [sp, #0x10];
    /* 0x45077c */ mov x29, sp;
    /* 0x450780 */ mov w0, #0x20;
    _Znwm();
    /* 0x450788 */ mov x19, x0;
    _ZN11LayerFlowNS19LFSetLayerPluginJNIC2Ev();
    /* 0x450790 */ adrp x0, #0x1d9000;
    /* 0x450794 */ add x0, x0, #0x93c;
    /* 0x450798 */ adrp x2, #0x1e4000;
    /* 0x45079c */ add x2, x2, #0x3ec;
    _ZN12MTImageKitNS8CMTIKLog3logEPKciS2_z();
    return x0;
    _ZdlPv();
    sub_526544();
}
