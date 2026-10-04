// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2d43a0
// Recovered Name: _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2d43a0 | Size: 84 bytes | SHA256: c3dd9e13e4d24c203f880c8f557a77b1f2d81c33a0f377d40a402d2193a31f3d
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroyResult(J)V (table at 0x5357c8)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyResult is called, addr => %p"

jobject _ZN11LayerFlowNS23LFEffectWakeSkinDataJNI14nDestroyResultEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 21 instructions
    /* 0x2d43a0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2d43a4 */ str x19, [sp, #0x10];
    /* 0x2d43a8 */ mov x29, sp;
    /* 0x2d43ac */ mov x19, x2;
    /* 0x2d43b0 */ nop ;
    /* 0x2d43b4 */ adr x1, #0x1e1361;
    /* 0x2d43b8 */ adrp x2, #0x1d5000;
    /* 0x2d43bc */ add x2, x2, #0x426;
    /* 0x2d43c0 */ mov w0, #6;
    /* 0x2d43c4 */ mov x3, x19;
    __android_log_print();
    _ZN16LFWakeSkinResultD2Ev();
    return x0;
}
