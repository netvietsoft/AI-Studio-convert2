// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x579da8
// Recovered Name: sub_579da8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x579da8 | Size: 20 bytes | SHA256: aef21a3e261a69a6e9ddabe8706649903a0ae8921a104e59495c94bf8ddb4464
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetParamTableType(J)I (table at 0x10ce390)

jlong sub_579da8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x579da8 */ cbz x2, #0x579db4;
    /* 0x579dac */ mov x0, x2;
    /* 0x579db0 */ b #0x8e0dd0;
    /* 0x579db4 */ mov w0, #-1;
    return x0;
}
