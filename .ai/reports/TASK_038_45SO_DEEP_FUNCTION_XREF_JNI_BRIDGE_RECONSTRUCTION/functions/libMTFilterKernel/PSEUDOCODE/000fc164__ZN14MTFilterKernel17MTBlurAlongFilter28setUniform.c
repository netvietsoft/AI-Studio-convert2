// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xfc164
// Recovered Name: _ZN14MTFilterKernel17MTBlurAlongFilter28setUniformsForProgramAtIndexEi
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xfc164 | Size: 16 bytes | SHA256: e4f0c489244c5c42301eaff4e8aaf73bd7eda011144c15c1ecade6ac3ace16f9
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel17MTBlurAlongFilter28setUniformsForProgramAtIndexEi(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xfc164 */ cmp w1, #2;
    /* 0xfc168 */ b.ne #0xfc278;
    /* 0xfc16c */ str d10, [sp, #-0x40]!;
    /* 0xfc170 */ stp d9, d8, [sp, #8];
}
