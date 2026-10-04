// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x59ef3c
// Recovered Name: _ZN11arkernelcpp39ARKernelSlimPhotoV1PartControlInterface17GetMaxSupportBodyEv
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x59ef3c | Size: 20 bytes | SHA256: 70df334529ddbe45dcef33520ca083a11d1bd512eacadaf95e5c70be811e57f0
// Callers: 0 | Callees: 0 | Imports: 0


void _ZN11arkernelcpp39ARKernelSlimPhotoV1PartControlInterface17GetMaxSupportBodyEv(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x59ef3c */ ldr x0, [x0, #8];
    /* 0x59ef40 */ cbz x0, #0x59ef48;
    /* 0x59ef44 */ b #0x985274;
    /* 0x59ef48 */ mov x0, #-1;
    return x0;
}
