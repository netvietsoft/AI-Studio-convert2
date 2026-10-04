// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579238
// Recovered Name: sub_579238
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579238 | Size: 28 bytes | SHA256: 93923610018e62264c71b28caa151fa1323c30af4d315f0d8ca802706f2f1fe2
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetApply(JZ)V (table at 0x10ce258)

jlong sub_579238(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x579238 */ cbz x2, #0x579250;
    /* 0x57923c */ and w8, w3, #0xff;
    /* 0x579240 */ mov x0, x2;
    /* 0x579244 */ cmp w8, #1;
    /* 0x579248 */ cset w1, eq;
    /* 0x57924c */ b #0x8e0ab8;
    return x0;
}
