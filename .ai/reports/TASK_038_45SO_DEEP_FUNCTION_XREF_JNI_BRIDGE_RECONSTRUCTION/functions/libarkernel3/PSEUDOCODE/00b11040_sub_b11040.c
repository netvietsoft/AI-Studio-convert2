// Library: libarkernel3.so
// Function ID: libarkernel3::0xb11040
// Recovered Name: sub_b11040
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xb11040 | Size: 140 bytes | SHA256: d4032a53c6b25e1740f758889207db589d4e8a2b9369c9f1c65a1b6f78252390
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeInitBitmapDC(II[BII)V (table at 0x10f9230)
// Calls external APIs: malloc

jlong sub_b11040(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 35 instructions
    /* 0xb11040 */ stp x29, x30, [sp, #-0x50]!;
    /* 0xb11044 */ stp x26, x25, [sp, #0x10];
    /* 0xb11048 */ stp x24, x23, [sp, #0x20];
    /* 0xb1104c */ stp x22, x21, [sp, #0x30];
    /* 0xb11050 */ stp x20, x19, [sp, #0x40];
    /* 0xb11054 */ mov x29, sp;
    /* 0xb11058 */ mul w8, w2, w3;
    /* 0xb1105c */ mov w19, w6;
    /* 0xb11060 */ mov w20, w5;
    /* 0xb11064 */ mov x21, x4;
    /* 0xb11068 */ mov w22, w3;
    sub_b10b7c();
    malloc();
}
