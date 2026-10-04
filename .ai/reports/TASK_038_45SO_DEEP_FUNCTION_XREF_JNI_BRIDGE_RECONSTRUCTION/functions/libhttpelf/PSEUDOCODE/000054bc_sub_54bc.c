// Library: libhttpelf.so
// Function ID: libhttpelf::0x54bc
// Recovered Name: sub_54bc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x54bc | Size: 1340 bytes | SHA256: c8d5940f9ea2d6b5d975799ba92083a55080d8afbdc867aa9bb568df2cd99d71
// Callers: 0 | Callees: 12 | Imports: 4

// Calls external APIs: __stack_chk_fail, memcpy, strcpy, strlen

void sub_54bc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 335 instructions
    /* 0x54bc */ stp x29, x30, [sp, #0x10];
    /* 0x54c0 */ stp x26, x25, [sp, #0x20];
    /* 0x54c4 */ stp x24, x23, [sp, #0x30];
    /* 0x54c8 */ stp x22, x21, [sp, #0x40];
    /* 0x54cc */ stp x20, x19, [sp, #0x50];
    /* 0x54d0 */ add x29, sp, #0x10;
    /* 0x54d4 */ mrs x25, tpidr_el0;
    /* 0x54d8 */ mov x19, x2;
    /* 0x54dc */ mov x20, x0;
    /* 0x54e0 */ ldr x8, [x25, #0x28];
    /* 0x54e4 */ mov x21, xzr;
    sub_5ca8();
    sub_6378();
    sub_5ad8();
    sub_64b8();
    memcpy();
    strlen();
    sub_64b0();
    strcpy();
    sub_5aac();
    strlen();
    sub_64b0();
    strcpy();
    strlen();
    sub_64b0();
    strcpy();
    strlen();
    sub_64b0();
    strcpy();
    sub_64b8();
    memcpy();
    sub_5a70();
    sub_5aa0();
    sub_64b0();
    sub_5a88();
    sub_64b0();
    sub_5a64();
    sub_64b0();
    sub_5a94();
    sub_64b0();
    sub_5a7c();
    return x0;
    __stack_chk_fail();
}
