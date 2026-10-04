// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b6ec
// Recovered Name: sub_57b6ec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b6ec | Size: 20 bytes | SHA256: c84045bccaed70566bafa4e44d5bbbbca7cf38a8749c321668dbd88219c3ae42
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetIsIdenticalInputStream(JZ)V (table at 0x10ce900)

jlong sub_57b6ec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b6ec */ cbz x2, #0x57b6fc;
    /* 0x57b6f0 */ tst w3, #0xff;
    /* 0x57b6f4 */ cset w8, ne;
    /* 0x57b6f8 */ strb w8, [x2, #0x1e];
    return x0;
}
