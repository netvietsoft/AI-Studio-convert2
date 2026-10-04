// Library: libLayerFlow.so
// Function ID: libLayerFlow::0x2ec4fc
// Recovered Name: _ZN22LFMakeupRuntimeDataJNI7nCreateEP7_JNIEnvP8_jobject
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x2ec4fc | Size: 56 bytes | SHA256: c6c905c7ab828f3c40c94e788475b36fc3b298bcc23684842980d5defcf4ec01
// Callers: 0 | Callees: 0 | Imports: 1

// Dynamic Registration: nCreate()J (table at 0x538f70)
// Calls external APIs: _Znwm

jobject _ZN22LFMakeupRuntimeDataJNI7nCreateEP7_JNIEnvP8_jobject(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 14 instructions
    /* 0x2ec4fc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x2ec500 */ mov x29, sp;
    /* 0x2ec504 */ mov w0, #0x30;
    _Znwm();
    /* 0x2ec50c */ movi v0.2d, #0000000000000000;
    /* 0x2ec510 */ mov x8, x0;
    /* 0x2ec514 */ add x9, x0, #8;
    /* 0x2ec518 */ str xzr, [x0, #0x28];
    /* 0x2ec51c */ str xzr, [x8, #0x20]!;
    /* 0x2ec520 */ stp q0, q0, [x0];
    /* 0x2ec524 */ str x9, [x0];
    return x0;
}
