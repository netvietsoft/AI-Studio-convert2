// Library: libarkernel3.so
// Function ID: libarkernel3::0x56b718
// Recovered Name: _ZNK8mtlabar311DataRequire26requireHairMaskAdditionCPUEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x56b718 | Size: 12 bytes | SHA256: 88a6ce02772a4de31524398fc6bfa5c96df6120f307221ce42b64de15ce42edd
// Callers: 0 | Callees: 0 | Imports: 0


void _ZNK8mtlabar311DataRequire26requireHairMaskAdditionCPUEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x56b718 */ ldrb w8, [x0, #4];
    /* 0x56b71c */ ubfx w0, w8, #6, #1;
    return x0;
}
