// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2decf4
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2decf4 | Size: 164 bytes | SHA256: 8a828bddb591be5d9a1fbe823913266abe3412bcf49f54f7eb21ef3260c2e355
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nDestroy(J)V (table at 0x537750)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "nDestroyInfo is called, addr => %p"

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI12nDestroyInfoEP7_JNIEnvP7_jclassl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 41 instructions
    /* 0x2decf4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x2decf8 */ str x21, [sp, #0x10];
    /* 0x2decfc */ stp x20, x19, [sp, #0x20];
    /* 0x2ded00 */ mov x29, sp;
    /* 0x2ded04 */ mov x19, x2;
    /* 0x2ded08 */ nop ;
    /* 0x2ded0c */ adr x1, #0x1e9177;
    /* 0x2ded10 */ adrp x2, #0x1d6000;
    /* 0x2ded14 */ add x2, x2, #0x8c6;
    /* 0x2ded18 */ mov w0, #6;
    /* 0x2ded1c */ mov x3, x19;
    __android_log_print();
    sub_2e1600();
    _ZdlPv();
    _ZdlPv();
    return x0;
}
