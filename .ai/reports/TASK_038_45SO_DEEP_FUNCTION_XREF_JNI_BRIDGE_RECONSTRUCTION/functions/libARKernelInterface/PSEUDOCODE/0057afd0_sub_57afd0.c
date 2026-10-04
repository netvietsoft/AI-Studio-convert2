// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57afd0
// Recovered Name: sub_57afd0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57afd0 | Size: 256 bytes | SHA256: f935766713c123f1dd4088d32487676aa64652e81c24273e669001ea7cbdaee5
// Callers: 0 | Callees: 4 | Imports: 4

// Dynamic Registration: nativeGetPlistDataJSONBuffer(J)Ljava/lang/String; (table at 0x10ce750)
// Calls external APIs: __cxa_atexit, __cxa_guard_abort, __cxa_guard_acquire, __cxa_guard_release

jlong sub_57afd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 64 instructions
    /* 0x57afd0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x57afd4 */ stp x20, x19, [sp, #0x10];
    /* 0x57afd8 */ mov x29, sp;
    /* 0x57afdc */ adrp x8, #0x1108000;
    /* 0x57afe0 */ add x8, x8, #0x4a0;
    /* 0x57afe4 */ mov x20, x2;
    /* 0x57afe8 */ ldarb w8, [x8];
    /* 0x57afec */ mov x19, x0;
    /* 0x57aff0 */ tbz w8, #0, #0x57b068;
    /* 0x57aff4 */ cbz x20, #0x57b038;
    /* 0x57aff8 */ mov x0, x20;
    sub_90b234();
    sub_90b228();
    return x0;
    __cxa_guard_acquire();
    sub_57a6c4();
    __cxa_atexit();
    __cxa_guard_release();
    __cxa_guard_abort();
    sub_1042be4();
}
