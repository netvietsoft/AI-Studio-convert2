// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xe30d4
// Recovered Name: _ZN14MTFilterKernel18MTImageBlendFilter17isNeedBodySegmentEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0xe30d4 | Size: 16 bytes | SHA256: 63a43a714e8bd1c969af683117cc6086d52cf01046ced19dd5c6c0e60a7b672e
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN14MTFilterKernel18MTImageBlendFilter17isNeedBodySegmentEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0xe30d4 */ ldr w8, [x0, #0x40];
    /* 0xe30d8 */ cmp w8, #0;
    /* 0xe30dc */ cset w0, gt;
    return x0;
}
