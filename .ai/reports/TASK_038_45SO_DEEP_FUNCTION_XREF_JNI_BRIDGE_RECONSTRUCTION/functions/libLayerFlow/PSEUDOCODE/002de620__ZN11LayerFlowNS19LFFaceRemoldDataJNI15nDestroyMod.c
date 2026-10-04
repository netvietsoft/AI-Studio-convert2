// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2de620
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2de620 | Size: 120 bytes | SHA256: 0261cb809b176850d8874238aa94bc6e6afba9f0608c26afb631f41a4b959c4d
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x537648)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyModular is called, addr => %p"

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI15nDestroyModularEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x2de620 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2de624 */ str x19, [sp, #0x10];
    /* 0x2de628 */ mov x29, sp;
    /* 0x2de62c */ mov x19, x2;
    /* 0x2de630 */ nop ;
    /* 0x2de634 */ adr x1, #0x1e9177;
    /* 0x2de638 */ adrp x2, #0x1d8000;
    /* 0x2de63c */ add x2, x2, #0xa68;
    /* 0x2de640 */ mov w0, #6;
    /* 0x2de644 */ mov x3, x19;
    __android_log_print();
    sub_2e0b94();
    _ZdlPv();
    return x0;
}
