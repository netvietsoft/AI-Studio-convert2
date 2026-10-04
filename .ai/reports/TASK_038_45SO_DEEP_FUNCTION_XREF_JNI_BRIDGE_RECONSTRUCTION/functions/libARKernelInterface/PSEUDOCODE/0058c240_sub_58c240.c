// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c240
// Recovered Name: sub_58c240
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c240 | Size: 152 bytes | SHA256: 8dad8c14e08390d3b020180f5c07cbc34e1c0a29e3453430ec7cc90aabd32f35
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nFinalizer(J)V (table at 0x10d0898)
// Calls external APIs: _ZdlPv, __android_log_print
// Strings referenced:
//   "arkernel"
//   "makeupcolor finalizer"

jlong sub_58c240(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x58c240 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58c244 */ str x19, [sp, #0x10];
    /* 0x58c248 */ mov x29, sp;
    /* 0x58c24c */ adrp x8, #0x10c5000;
    /* 0x58c250 */ mov x19, x2;
    /* 0x58c254 */ ldr x8, [x8, #0x7a8];
    /* 0x58c258 */ ldr w8, [x8];
    /* 0x58c25c */ cmp w8, #2;
    /* 0x58c260 */ b.gt #0x58c28c;
    /* 0x58c264 */ adrp x8, #0x1108000;
    /* 0x58c268 */ add x8, x8, #0x8f8;
    sub_5a6b20();
    _ZdlPv();
    __android_log_print();
    return x0;
}
