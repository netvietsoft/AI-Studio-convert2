// Library: libarkernel3_c.so
// Function ID: libarkernel3_c::0x5d2e4
// Recovered Name: SWIG_exit
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x5d2e4 | Size: 28 bytes | SHA256: 9bcc3ddb3075236c64816e0a1df73144bb450912b232698ca3b0bf7b63b7d6a0
// Callers: 0 | Callees: 1 | Imports: 1

// Calls external APIs: exit

void SWIG_exit(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x5d2e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x5d2e8 */ str x19, [sp, #0x10];
    /* 0x5d2ec */ mov x29, sp;
    /* 0x5d2f0 */ mov w19, w0;
    sub_5d300();
    /* 0x5d2f8 */ mov w0, w19;
    exit();
}
