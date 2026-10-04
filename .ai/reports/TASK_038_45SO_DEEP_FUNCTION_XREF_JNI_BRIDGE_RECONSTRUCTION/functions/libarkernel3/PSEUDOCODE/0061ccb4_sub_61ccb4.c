// Library: libarkernel3.so
// Function ID: libarkernel3::0x61ccb4
// Recovered Name: sub_61ccb4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x61ccb4 | Size: 176 bytes | SHA256: e5e6b5b1a899e642a49bd4d633a7a784af1633f965c4904a60427bf54f7898c9
// Callers: 0 | Callees: 3 | Imports: 1

// Calls external APIs: __stack_chk_fail
// Strings referenced:
//   "GPInstanceSegmentData"

void sub_61ccb4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 44 instructions
    /* 0x61ccb4 */ stp x29, x30, [sp, #0x30];
    /* 0x61ccb8 */ str x21, [sp, #0x40];
    /* 0x61ccbc */ stp x20, x19, [sp, #0x50];
    /* 0x61ccc0 */ add x29, sp, #0x30;
    /* 0x61ccc4 */ mrs x19, tpidr_el0;
    /* 0x61ccc8 */ ldr x8, [x19, #0x28];
    /* 0x61cccc */ stur x8, [x29, #-8];
    /* 0x61ccd0 */ stp xzr, xzr, [sp, #8];
    /* 0x61ccd4 */ str xzr, [sp, #0x18];
    /* 0x61ccd8 */ adrp x0, #0x24f000;
    /* 0x61ccdc */ add x0, x0, #0xbeb;
    sub_e2e10c();
    sub_5687b4();
    return x0;
    sub_5687b4();
    sub_106b814();
    __stack_chk_fail();
}
