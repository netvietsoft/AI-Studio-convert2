// Library: libarkernel3.so
// Function ID: libarkernel3::0xaa0508
// Recovered Name: sub_aa0508
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaa0508 | Size: 676 bytes | SHA256: 8eeb3dd69ae96474e298a93ddecdd10c1129ba3cb33d50776d03acb0698960e1
// Callers: 1 | Callees: 4 | Imports: 0

// Strings referenced:
//   "EnableBodySegmentProcess"
//   "EnableProfileEyeOptimization"
//   "EnableSegmentFaceProcess"
//   "EnableSegmentFaceWith2p5DEffect"
//   "EnableSegmentMouthProcess"

void sub_aa0508(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 169 instructions
    /* 0xaa0508 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xaa050c */ str x21, [sp, #0x10];
    /* 0xaa0510 */ stp x20, x19, [sp, #0x20];
    /* 0xaa0514 */ mov x29, sp;
    /* 0xaa0518 */ mov x19, x0;
    /* 0xaa051c */ mov x0, x1;
    /* 0xaa0520 */ mov x20, x1;
    sub_b693e8();
    /* 0xaa0528 */ adrp x1, #0x221000;
    /* 0xaa052c */ add x1, x1, #0x8eb;
    /* 0xaa0530 */ mov x0, x20;
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b67b58();
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    return x0;
}
