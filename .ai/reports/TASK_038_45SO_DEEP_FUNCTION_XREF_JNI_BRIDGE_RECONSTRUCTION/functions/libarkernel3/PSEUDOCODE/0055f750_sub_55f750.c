// Library: libarkernel3.so
// Function ID: libarkernel3::0x55f750
// Recovered Name: sub_55f750
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55f750 | Size: 152 bytes | SHA256: fe4145c30c0d84bcc9715e47ab3ef517cd322ff3068bab66970a745d2431be01
// Callers: 8 | Callees: 2 | Imports: 2

// Calls external APIs: _ZdlPv, memset

void sub_55f750(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x55f750 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x55f754 */ str x21, [sp, #0x10];
    /* 0x55f758 */ stp x20, x19, [sp, #0x20];
    /* 0x55f75c */ mov x29, sp;
    /* 0x55f760 */ stp xzr, xzr, [x0];
    /* 0x55f764 */ str xzr, [x0, #0x10];
    /* 0x55f768 */ cbz x1, #0x55f7b8;
    /* 0x55f76c */ mov x20, x1;
    /* 0x55f770 */ mov x19, x0;
    sub_56026c();
    /* 0x55f778 */ mov w8, #0x18;
    memset();
    return x0;
    _ZdlPv();
    sub_106b814();
}
