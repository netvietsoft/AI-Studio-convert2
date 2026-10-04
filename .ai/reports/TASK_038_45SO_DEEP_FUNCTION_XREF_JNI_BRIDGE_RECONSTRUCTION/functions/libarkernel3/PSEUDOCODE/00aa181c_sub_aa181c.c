// Library: libarkernel3.so
// Function ID: libarkernel3::0xaa181c
// Recovered Name: sub_aa181c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xaa181c | Size: 108 bytes | SHA256: 9c9a47ca6ef08be941b28be77a46292cfd32d54185d45a0fb79a28f57990729d
// Callers: 1 | Callees: 3 | Imports: 0

// Strings referenced:
//   "AdvanceMakeupHairMaskMidPoint"

void sub_aa181c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 27 instructions
    /* 0xaa181c */ stp x29, x30, [sp, #-0x30]!;
    /* 0xaa1820 */ str x21, [sp, #0x10];
    /* 0xaa1824 */ stp x20, x19, [sp, #0x20];
    /* 0xaa1828 */ mov x29, sp;
    /* 0xaa182c */ mov x19, x0;
    /* 0xaa1830 */ mov x0, x1;
    /* 0xaa1834 */ mov x21, x1;
    sub_b693e8();
    /* 0xaa183c */ adrp x1, #0x23b000;
    /* 0xaa1840 */ add x1, x1, #0x593;
    /* 0xaa1844 */ mov x0, x21;
    sub_b693f0();
    sub_b693e8();
    sub_b68184();
    return x0;
}
