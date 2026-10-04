// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d650
// Recovered Name: sub_57d650
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d650 | Size: 20 bytes | SHA256: eb93296c3854855d1d9e3dc7fec0a87e821b308999e47b2d8d26b82840eb69d9
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerMaxValue(J)I (table at 0x10cee58)

jlong sub_57d650(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d650 */ cbz x2, #0x57d65c;
    /* 0x57d654 */ ldr w0, [x2, #0x1c];
    return x0;
    /* 0x57d65c */ mov w0, wzr;
    return x0;
}
