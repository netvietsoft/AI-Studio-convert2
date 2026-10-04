// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579ef4
// Recovered Name: sub_579ef4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579ef4 | Size: 20 bytes | SHA256: 7ca57aa14deca9127ebe883ec14cffba50da73174467e1434759eaeb243714ce
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetPlistTag(J)J (table at 0x10ce468)

jlong sub_579ef4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579ef4 */ cbz x2, #0x579f00;
    /* 0x579ef8 */ mov x0, x2;
    /* 0x579efc */ b #0x90a69c;
    /* 0x579f00 */ mov x0, xzr;
    return x0;
}
