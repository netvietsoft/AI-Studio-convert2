// Library: libfftw3.so
// Function ID: libfftw3::0x19d84
// Recovered Name: fftwf_ifree0
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x19d84 | Size: 12 bytes | SHA256: 708ad1fc1a460388af9ee7d7f6e55e336dd1d85bf03138d61226b28298628e7a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: fftwf_kernel_free

void fftwf_ifree0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x19d84 */ cbz x0, #0x19d8c;
    /* 0x19d88 */ b #0x75ab0;
    return x0;
}
