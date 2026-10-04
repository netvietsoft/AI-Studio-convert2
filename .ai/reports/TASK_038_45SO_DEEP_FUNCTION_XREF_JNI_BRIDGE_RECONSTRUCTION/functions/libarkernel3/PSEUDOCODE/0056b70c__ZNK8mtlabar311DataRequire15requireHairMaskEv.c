// Library: libarkernel3.so
// Function ID: libarkernel3::0x56b70c
// Recovered Name: _ZNK8mtlabar311DataRequire15requireHairMaskEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x56b70c | Size: 12 bytes | SHA256: c5e673d94419943b1f7b5fff868deac53f74314a4a935c1ad730309922fde82c
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK8mtlabar311DataRequire15requireHairMaskEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x56b70c */ ldrb w8, [x0, #4];
    /* 0x56b710 */ ubfx w0, w8, #5, #1;
    return x0;
}
