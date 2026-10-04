// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b69c
// Recovered Name: sub_57b69c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b69c | Size: 20 bytes | SHA256: 1427eff40b585e4976b99766eb1ea111e46d512895317b06bd0d1805b07f0fe7
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetIsCaptureFrame(JZ)V (table at 0x10ce8a0)

jlong sub_57b69c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b69c */ cbz x2, #0x57b6ac;
    /* 0x57b6a0 */ tst w3, #0xff;
    /* 0x57b6a4 */ cset w8, ne;
    /* 0x57b6a8 */ strb w8, [x2, #0x1c];
    return x0;
}
