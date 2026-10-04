// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xdb924
// Recovered Name: _ZN14MTFilterKernel22MTDefocusManagerFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xdb924 | Size: 16 bytes | SHA256: f56e404321f0e5a50cc99502cabdfcb7862eea9c52d41fecb46f91f741782868
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel22MTDefocusManagerFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xdb924 */ ldrb w8, [x0, #0xd8];
    /* 0xdb928 */ cmp w8, #0;
    /* 0xdb92c */ cset w0, eq;
    return x0;
}
