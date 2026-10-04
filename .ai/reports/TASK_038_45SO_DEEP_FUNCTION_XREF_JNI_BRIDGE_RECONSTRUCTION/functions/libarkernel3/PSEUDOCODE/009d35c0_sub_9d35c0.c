// Library: libarkernel3.so
// Function ID: libarkernel3::0x9d35c0
// Recovered Name: sub_9d35c0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x9d35c0 | Size: 188 bytes | SHA256: 6700e9d405530d07a3bd77c45b545bbcb84b4a90457e6a67f650ef10ad1784e4
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "const char *utils::getClassUniqueString() [T = mtlabar3::SegmentStrokeObjPart]"

void sub_9d35c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 47 instructions
    /* 0x9d35c0 */ stp x29, x30, [sp, #0x50];
    /* 0x9d35c4 */ str x21, [sp, #0x60];
    /* 0x9d35c8 */ stp x20, x19, [sp, #0x70];
    /* 0x9d35cc */ add x29, sp, #0x50;
    /* 0x9d35d0 */ mrs x20, tpidr_el0;
    /* 0x9d35d4 */ mov x19, x0;
    /* 0x9d35d8 */ ldr x8, [x20, #0x28];
    /* 0x9d35dc */ stur x8, [x29, #-8];
    sub_655fd4();
    /* 0x9d35e4 */ movi v0.2d, #0000000000000000;
    /* 0x9d35e8 */ adrp x8, #0x26c000;
    sub_65616c();
    sub_65616c();
    return x0;
    __stack_chk_fail();
}
