// Library: libAIModelKit.so
// Function ID: libAIModelKit::0x1b764
// Recovered Name: _Z20parseManisDeviceInfoPKci
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x1b764 | Size: 12 bytes | SHA256: c80655b8a6aa845170f64cec08f78ab41528bc87b6a668124e9b0455d4664b01
// Callers: 0 | Callees: 0 | Imports: 0


void _Z20parseManisDeviceInfoPKci(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 3 instructions
    /* 0x1b764 */ cbz x0, #0x1b888;
    /* 0x1b768 */ cmp w1, #0;
    /* 0x1b76c */ b.le #0x1b888;
}
