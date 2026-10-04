// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57b714
// Recovered Name: sub_57b714
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57b714 | Size: 20 bytes | SHA256: 283295db0a71983318f6a2445d3d4485fc3df427b697e6fd5b64bd5f92e04037
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeSetIsFirstFrame(JZ)V (table at 0x10ce930)

jlong sub_57b714(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57b714 */ cbz x2, #0x57b724;
    /* 0x57b718 */ tst w3, #0xff;
    /* 0x57b71c */ cset w8, ne;
    /* 0x57b720 */ strb w8, [x2, #0x1f];
    return x0;
}
