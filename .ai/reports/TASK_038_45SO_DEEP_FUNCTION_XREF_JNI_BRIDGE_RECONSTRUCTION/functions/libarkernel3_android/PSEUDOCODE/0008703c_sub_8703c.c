// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8703c
// Recovered Name: sub_8703c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x8703c | Size: 48 bytes | SHA256: 9a852eb4340306cbf2c6368c49a6dfbda2d0a647ad1c2fbde5b9ddfeac574147
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNSt11logic_errorC2EPKc

void sub_8703c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 12 instructions
    /* 0x8703c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x87040 */ str x19, [sp, #0x10];
    /* 0x87044 */ mov x29, sp;
    /* 0x87048 */ mov x19, x0;
    _ZNSt11logic_errorC2EPKc();
    /* 0x87050 */ adrp x8, #0xaa000;
    /* 0x87054 */ ldr x8, [x8, #0x50];
    /* 0x87058 */ add x8, x8, #0x10;
    /* 0x8705c */ str x8, [x19];
    /* 0x87060 */ ldr x19, [sp, #0x10];
    /* 0x87064 */ ldp x29, x30, [sp], #0x20;
    return x0;
}
