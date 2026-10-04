// Library: libfantasy.so
// Function ID: libfantasy::0xba800
// Recovered Name: sub_ba800
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xba800 | Size: 100 bytes | SHA256: 744d3ddc68f4b622c09107e1692b6a0bf66ff9762bd2761881af7aa13191525e
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: __stack_chk_fail

void sub_ba800(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 25 instructions
    /* 0xba800 */ stp x29, x30, [sp, #0x10];
    /* 0xba804 */ stp x20, x19, [sp, #0x20];
    /* 0xba808 */ add x29, sp, #0x10;
    /* 0xba80c */ mrs x20, tpidr_el0;
    /* 0xba810 */ mov x19, x0;
    /* 0xba814 */ mov w2, w1;
    /* 0xba818 */ ldr x8, [x20, #0x28];
    /* 0xba81c */ add x0, x0, #0x80;
    /* 0xba820 */ str x8, [sp, #8];
    /* 0xba824 */ str w1, [sp, #4];
    /* 0xba828 */ add x1, sp, #4;
    sub_bb61c();
    return x0;
    __stack_chk_fail();
}
