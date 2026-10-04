// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ee3cc
// Recovered Name: _ZN11LayerFlowNS19LFSkinWhitenDataJNI11nCreateInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ee3cc | Size: 176 bytes | SHA256: 213f45c47f8f45f27988511ac07f525e72100e358913a69cfb26e23dcc794035
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x539660)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "iklf_"
//   "nCreateInfo is called, addr => %p"

jobject _ZN11LayerFlowNS19LFSkinWhitenDataJNI11nCreateInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x2ee3cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2ee3d0 */ str x19, [sp, #0x10];
    /* 0x2ee3d4 */ mov x29, sp;
    /* 0x2ee3d8 */ mov w0, #0xe0;
    _Znwm();
    /* 0x2ee3e0 */ movi v0.2d, #0000000000000000;
    /* 0x2ee3e4 */ mov x19, x0;
    /* 0x2ee3e8 */ mov w8, #-1;
    /* 0x2ee3ec */ mov w9, #0x64;
    /* 0x2ee3f0 */ adrp x1, #0x1e1000;
    /* 0x2ee3f4 */ add x1, x1, #0x361;
    __android_log_print();
    return x0;
}
