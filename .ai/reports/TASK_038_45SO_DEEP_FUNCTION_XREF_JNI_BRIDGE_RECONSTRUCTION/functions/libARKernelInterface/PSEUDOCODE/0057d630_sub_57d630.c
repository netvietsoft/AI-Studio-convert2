// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d630
// Recovered Name: sub_57d630
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d630 | Size: 20 bytes | SHA256: 03c5cc5a540751e2094dc346e399af1bfc3121318094711b42d0ce8bb2a371aa
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerMinValue(J)I (table at 0x10cee28)

jlong sub_57d630(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d630 */ cbz x2, #0x57d63c;
    /* 0x57d634 */ ldr w0, [x2, #0x18];
    return x0;
    /* 0x57d63c */ mov w0, wzr;
    return x0;
}
