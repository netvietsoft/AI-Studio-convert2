// Library: libMTGif.so
// Function ID: libMTGif::0x8640
// Recovered Name: _ZN13FormatConvert18ImageParamsInitialEPNS_12_ImageParamsE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x8640 | Size: 44 bytes | SHA256: 10a10cd78dfecbdb363275033cfdf26a2fd4cba2a23b6482e2b2faa6ecbc13f8
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN13FormatConvert18ImageParamsInitialEPNS_12_ImageParamsE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x8640 */ cbz x0, #0x8668;
    /* 0x8644 */ mov w8, #-1;
    /* 0x8648 */ stp wzr, wzr, [x0, #4];
    /* 0x864c */ str w8, [x0];
    /* 0x8650 */ mov w8, #1;
    /* 0x8654 */ str xzr, [x0, #0x10];
    /* 0x8658 */ str w8, [x0, #0x18];
    /* 0x865c */ stur xzr, [x0, #0x24];
    /* 0x8660 */ stur xzr, [x0, #0x1c];
    /* 0x8664 */ str wzr, [x0, #0x2c];
    return x0;
}
