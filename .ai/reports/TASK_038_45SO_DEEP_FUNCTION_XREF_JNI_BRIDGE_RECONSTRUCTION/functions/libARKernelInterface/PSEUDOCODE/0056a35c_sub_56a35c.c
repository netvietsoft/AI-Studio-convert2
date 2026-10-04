// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a35c
// Recovered Name: sub_56a35c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a35c | Size: 32 bytes | SHA256: 80a35949369848e464e56474b5bb818d4ce63a3dbcb3747e35cab619891a478b
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetRightEarPointCount2D(JI)I (table at 0x10cd160)

jlong sub_56a35c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x56a35c */ mov w0, wzr;
    /* 0x56a360 */ cbz x2, #0x56a378;
    /* 0x56a364 */ cmp w3, #0x13;
    /* 0x56a368 */ b.hi #0x56a378;
    /* 0x56a36c */ mov w8, #0x5c0;
    /* 0x56a370 */ umaddl x8, w3, w8, x2;
    /* 0x56a374 */ ldr w0, [x8, #0x1d0];
    return x0;
}
