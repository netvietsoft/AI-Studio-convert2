// Library: libPVGCodec.so
// Function ID: libPVGCodec::0x1210f4
// Recovered Name: sub_1210f4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x1210f4 | Size: 20 bytes | SHA256: 42805950b5d8c6b005d29e347933350597e8b32a82857fdb0e2f5b058083d183
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: native_getError(J)I (table at 0x13a7c0)

jlong sub_1210f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x1210f4 */ cbz x2, #0x121108;
    /* 0x1210f8 */ ldr x8, [x2];
    /* 0x1210fc */ mov x0, x2;
    /* 0x121100 */ ldr x1, [x8, #0x50];
    /* 0x121104 */ br x1;
}
