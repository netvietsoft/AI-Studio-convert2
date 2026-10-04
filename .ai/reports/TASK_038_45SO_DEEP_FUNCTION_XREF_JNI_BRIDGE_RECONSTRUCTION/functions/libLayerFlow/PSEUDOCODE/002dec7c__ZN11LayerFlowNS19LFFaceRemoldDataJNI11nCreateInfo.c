// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2dec7c
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI11nCreateInfoEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2dec7c | Size: 120 bytes | SHA256: 1d677281b631d202d8348c0ee2d3622dbf0d1f0ac7161e390aa7f88c6a3bd65c
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x537738)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "nCreateInfo is called, addr => %p"

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI11nCreateInfoEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 30 instructions
    /* 0x2dec7c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2dec80 */ str x19, [sp, #0x10];
    /* 0x2dec84 */ mov x29, sp;
    /* 0x2dec88 */ mov w0, #0x60;
    _Znwm();
    /* 0x2dec90 */ movi v0.2d, #0000000000000000;
    /* 0x2dec94 */ mov w8, #0x3f800000;
    /* 0x2dec98 */ mov x19, x0;
    /* 0x2dec9c */ nop ;
    /* 0x2deca0 */ adr x1, #0x1e9177;
    /* 0x2deca4 */ adrp x2, #0x1e1000;
    __android_log_print();
    return x0;
}
