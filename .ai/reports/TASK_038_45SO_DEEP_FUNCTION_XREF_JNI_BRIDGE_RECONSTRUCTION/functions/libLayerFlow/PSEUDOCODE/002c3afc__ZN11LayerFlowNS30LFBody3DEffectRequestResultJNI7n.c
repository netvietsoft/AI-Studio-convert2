// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2c3afc
// Recovered Name: _ZN11LayerFlowNS30LFBody3DEffectRequestResultJNI7nCreateEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2c3afc | Size: 148 bytes | SHA256: 299e0480b5908676af2298654b288fc7f1242bee3cf51c6ab82e057e314cf8ab
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x532930)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "LFBody3DEffectRequestResultJNI::nCreate addr => %p"

jobject _ZN11LayerFlowNS30LFBody3DEffectRequestResultJNI7nCreateEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x2c3afc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2c3b00 */ str x19, [sp, #0x10];
    /* 0x2c3b04 */ mov x29, sp;
    /* 0x2c3b08 */ mov w0, #0x90;
    _Znwm();
    /* 0x2c3b10 */ movi v0.2d, #0000000000000000;
    /* 0x2c3b14 */ add x8, x0, #8;
    /* 0x2c3b18 */ mov x19, x0;
    /* 0x2c3b1c */ str xzr, [x0, #0x88];
    /* 0x2c3b20 */ nop ;
    /* 0x2c3b24 */ adr x1, #0x1e1361;
    __android_log_print();
    return x0;
}
