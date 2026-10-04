// Library: libarkernel3.so
// Function ID: libarkernel3::0x56b838
// Recovered Name: _ZNK8mtlabar311DataRequire11requireBodyEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x56b838 | Size: 12 bytes | SHA256: 64ab412dc12f7c78bc16fc670a97b48c58ac52200e0aea6d298327a669059fe9
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK8mtlabar311DataRequire11requireBodyEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x56b838 */ ldrb w8, [x0, #7];
    /* 0x56b83c */ ubfx w0, w8, #6, #1;
    return x0;
}
