// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2df8ac
// Recovered Name: _ZN11LayerFlowNS19LFFaceRemoldDataJNI15nCreateMaterialEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2df8ac | Size: 104 bytes | SHA256: 797756c4f140796e83b7ff4e8e06b88c775ad8457785f1b25e9d383c595bcd54
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x537858)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "nCreateMaterial is called, addr => %p"

jobject _ZN11LayerFlowNS19LFFaceRemoldDataJNI15nCreateMaterialEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 26 instructions
    /* 0x2df8ac */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2df8b0 */ str x19, [sp, #0x10];
    /* 0x2df8b4 */ mov x29, sp;
    /* 0x2df8b8 */ mov w0, #0x28;
    _Znwm();
    /* 0x2df8c0 */ movi v0.2d, #0000000000000000;
    /* 0x2df8c4 */ mov w8, #0x3f800000;
    /* 0x2df8c8 */ mov x19, x0;
    /* 0x2df8cc */ str xzr, [x0, #0x20];
    /* 0x2df8d0 */ nop ;
    /* 0x2df8d4 */ adr x1, #0x1e9177;
    __android_log_print();
    return x0;
}
