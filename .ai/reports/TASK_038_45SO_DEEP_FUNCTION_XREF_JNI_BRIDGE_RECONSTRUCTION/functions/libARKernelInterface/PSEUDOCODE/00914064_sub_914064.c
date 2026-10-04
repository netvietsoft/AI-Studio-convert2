// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x914064
// Recovered Name: sub_914064
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x914064 | Size: 204 bytes | SHA256: 77582a9cc7f8d7d0956906f534fc8c8d2876ce4a0c66eb4a63c6943eebd95fed
// Callers: 0 | Callees: 6 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "GetSegmentMask end "

void sub_914064(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x914064 */ stp x29, x30, [sp, #0x10];
    /* 0x914068 */ str x21, [sp, #0x20];
    /* 0x91406c */ stp x20, x19, [sp, #0x30];
    /* 0x914070 */ add x29, sp, #0x10;
    /* 0x914074 */ mrs x21, tpidr_el0;
    /* 0x914078 */ mov x19, x0;
    /* 0x91407c */ mov w1, #0x64;
    /* 0x914080 */ ldr x8, [x21, #0x28];
    /* 0x914084 */ add x2, x19, #0xda8;
    /* 0x914088 */ str x8, [sp, #8];
    /* 0x91408c */ str x0, [sp];
    sub_914130();
    sub_914130();
    sub_c38b3c();
    sub_69ac00();
    sub_69add8();
    sub_d7ffbc();
    sub_d7ffbc();
    sub_5f1fb4();
    return x0;
    __stack_chk_fail();
}
