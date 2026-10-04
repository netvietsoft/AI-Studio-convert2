// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x585504
// Recovered Name: sub_585504
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x585504 | Size: 32 bytes | SHA256: c63a8c2a73c80309d16b48b2c45ef8eb41eecc075261387cdc875e4e8cbd28b7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetLayerVisibility(JJZ)V (table at 0x10cfa88)

jlong sub_585504(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x585504 */ cbz x2, #0x585520;
    /* 0x585508 */ tst w4, #0xff;
    /* 0x58550c */ mov x0, x2;
    /* 0x585510 */ mov x1, x3;
    /* 0x585514 */ cset w8, ne;
    /* 0x585518 */ mov w2, w8;
    /* 0x58551c */ b #0x58438c;
    return x0;
}
