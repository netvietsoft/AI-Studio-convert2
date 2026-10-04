// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2f12e8
// Recovered Name: _ZN11LayerFlowNS34LFStraightLegsAIGCRequestResultJNI7nCreateEP7_JNIEnvP7_jclass
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2f12e8 | Size: 80 bytes | SHA256: 51f28ba67454b7d118bdb9ccc334e2716d759c579574accd990b21203593f1b0
// Callers: 0 | Callees: 0 | Imports: 2

// Dynamic Registration: nCreate()J (table at 0x53a570)
// Calls external APIs: _Znwm, __android_log_print
// Strings referenced:
//   "LFStraightLegsAIGCRequestResultJNI::nCreate addr => %p"
//   "iklf_"

jobject _ZN11LayerFlowNS34LFStraightLegsAIGCRequestResultJNI7nCreateEP7_JNIEnvP7_jclass(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 20 instructions
    /* 0x2f12e8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x2f12ec */ str x19, [sp, #0x10];
    /* 0x2f12f0 */ mov x29, sp;
    /* 0x2f12f4 */ mov w0, #0x30;
    _Znwm();
    /* 0x2f12fc */ movi v0.2d, #0000000000000000;
    /* 0x2f1300 */ mov x19, x0;
    /* 0x2f1304 */ adrp x1, #0x1e1000;
    /* 0x2f1308 */ add x1, x1, #0x361;
    /* 0x2f130c */ adrp x2, #0x1d6000;
    /* 0x2f1310 */ add x2, x2, #0xa2f;
    __android_log_print();
    return x0;
}
