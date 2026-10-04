// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x59f1fc
// Recovered Name: _ZN11arkernelcpp34ARKernelSlimV2PartControlInterface17SetSlimBodyEnableENS0_9BodyStyleEb
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x59f1fc | Size: 20 bytes | SHA256: 349d9a72b630bf0b5eb63eb5933d12fe4802990ba69e14e52b49627b29ac9933
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11arkernelcpp34ARKernelSlimV2PartControlInterface17SetSlimBodyEnableENS0_9BodyStyleEb(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x59f1fc */ ldr x0, [x0, #8];
    /* 0x59f200 */ cbz x0, #0x59f20c;
    /* 0x59f204 */ and w2, w2, #1;
    /* 0x59f208 */ b #0x9b2334;
    return x0;
}
