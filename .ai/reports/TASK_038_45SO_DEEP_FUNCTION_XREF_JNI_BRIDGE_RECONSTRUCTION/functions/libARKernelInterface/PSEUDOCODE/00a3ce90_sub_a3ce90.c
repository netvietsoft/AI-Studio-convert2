// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xa3ce90
// Recovered Name: sub_a3ce90
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa3ce90 | Size: 608 bytes | SHA256: 1c23010c36c68bbee99b738af1a199eed54c56dc5dd0cb80c7362b7dc1762cde
// Callers: 0 | Callees: 11 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "There is no this segment type: %d "

void sub_a3ce90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 152 instructions
    /* 0xa3ce90 */ stp x29, x30, [sp, #0x90];
    /* 0xa3ce94 */ stp x24, x23, [sp, #0xa0];
    /* 0xa3ce98 */ stp x22, x21, [sp, #0xb0];
    /* 0xa3ce9c */ stp x20, x19, [sp, #0xc0];
    /* 0xa3cea0 */ add x29, sp, #0x90;
    /* 0xa3cea4 */ mrs x24, tpidr_el0;
    /* 0xa3cea8 */ mov x20, x0;
    /* 0xa3ceac */ ldr x8, [x24, #0x28];
    /* 0xa3ceb0 */ stur x8, [x29, #-8];
    /* 0xa3ceb4 */ ldrb w8, [x0, #0xadc];
    /* 0xa3ceb8 */ cbnz w8, #0xa3cee0;
    sub_698564();
    sub_69856c();
    sub_c39340();
    sub_c39340();
    sub_c39340();
    sub_c39340();
    sub_c38b3c();
    sub_697fb4();
    sub_6981a0();
    sub_c39340();
    sub_697fb4();
    sub_6981a0();
    sub_c38b3c();
    sub_698448();
    sub_697894();
    return x0;
    sub_94e1e8();
    sub_a40f14();
    sub_a40fb8();
    __stack_chk_fail();
}
