// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x59eed4
// Recovered Name: _ZN11arkernelcpp39ARKernelSlimPhotoV1PartControlInterface13SetBodyEnableElb
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x59eed4 | Size: 20 bytes | SHA256: 9d44554b8ea034580709c3e223aacb89ac208faf4ed89bbbc557b183177e0363
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11arkernelcpp39ARKernelSlimPhotoV1PartControlInterface13SetBodyEnableElb(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x59eed4 */ ldr x0, [x0, #8];
    /* 0x59eed8 */ cbz x0, #0x59eee4;
    /* 0x59eedc */ and w2, w2, #1;
    /* 0x59eee0 */ b #0x9852b4;
    return x0;
}
