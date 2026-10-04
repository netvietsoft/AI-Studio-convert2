// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58bad4
// Recovered Name: sub_58bad4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58bad4 | Size: 332 bytes | SHA256: 1109d73bb3082ee442894616f3e33e6edc46db62de7e5cea555b41d125db92fe
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeDestroyInstance(J)V (table at 0x10d0820)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "arkernel"
//   "makeupcolor finalizer"

jlong sub_58bad4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 83 instructions
    /* 0x58bad4 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x58bad8 */ str x21, [sp, #0x10];
    /* 0x58badc */ stp x20, x19, [sp, #0x20];
    /* 0x58bae0 */ mov x29, sp;
    /* 0x58bae4 */ adrp x8, #0x10c5000;
    /* 0x58bae8 */ mov x19, x2;
    /* 0x58baec */ ldr x8, [x8, #0x7a8];
    /* 0x58baf0 */ ldr w8, [x8];
    /* 0x58baf4 */ cmp w8, #2;
    /* 0x58baf8 */ b.gt #0x58bb24;
    /* 0x58bafc */ adrp x8, #0x1108000;
    sub_5a6b20();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    __android_log_print();
    return x0;
}
