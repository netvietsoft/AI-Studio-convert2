// Library: libarkernel3.so
// Function ID: libarkernel3::0x9ee97c
// Recovered Name: sub_9ee97c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9ee97c | Size: 212 bytes | SHA256: df0ed1ffb658db766ef60d5b66e6d768d5a2fc2c1823b10c48d8297a133ed38c
// Callers: 0 | Callees: 5 | Imports: 2

// Calls external APIs: _ZdlPv, __stack_chk_fail
// Strings referenced:
//   "segment_erosion_9h"
//   "segment_erosion_9v"

void sub_9ee97c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x9ee97c */ stp x29, x30, [sp, #0x20];
    /* 0x9ee980 */ stp x22, x21, [sp, #0x30];
    /* 0x9ee984 */ stp x20, x19, [sp, #0x40];
    /* 0x9ee988 */ add x29, sp, #0x20;
    /* 0x9ee98c */ mrs x22, tpidr_el0;
    /* 0x9ee990 */ mov w20, w2;
    /* 0x9ee994 */ mov x19, x0;
    /* 0x9ee998 */ ldr x8, [x22, #0x28];
    /* 0x9ee99c */ stur x8, [x29, #-8];
    sub_9edd98();
    /* 0x9ee9a4 */ adrp x8, #0x109e000;
    sub_a7fc58();
    sub_5604d4();
    sub_a7b120();
    _ZdlPv();
    return x0;
    sub_106b814();
    __stack_chk_fail();
}
