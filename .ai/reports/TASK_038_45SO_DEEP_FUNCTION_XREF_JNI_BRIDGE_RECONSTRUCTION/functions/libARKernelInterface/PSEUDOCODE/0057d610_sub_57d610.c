// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57d610
// Recovered Name: sub_57d610
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57d610 | Size: 20 bytes | SHA256: d072b452f45eacf956c10571c543808841597bfa85d1a206990d8d124b1878e4
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nativeGetLayerVertexMarkRadius(J)I (table at 0x10cedf8)

jlong sub_57d610(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x57d610 */ cbz x2, #0x57d61c;
    /* 0x57d614 */ ldr w0, [x2, #0x14];
    return x0;
    /* 0x57d61c */ mov w0, wzr;
    return x0;
}
