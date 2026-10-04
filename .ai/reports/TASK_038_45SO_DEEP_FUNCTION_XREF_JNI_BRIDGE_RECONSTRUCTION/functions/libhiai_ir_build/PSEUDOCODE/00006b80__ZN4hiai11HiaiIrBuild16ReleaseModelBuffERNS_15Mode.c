// Library: libhiai_ir_build.so
// Function ID: libhiai_ir_build::0x6b80
// Recovered Name: _ZN4hiai11HiaiIrBuild16ReleaseModelBuffERNS_15ModelBufferDataE
// Visibility: EXPORTED | Confidence: FACT
// Address: 0x6b80 | Size: 36 bytes | SHA256: 39b93b3d0ee8adb0dd0d674ec863423fcf9ed27c228ed5850ad6f4bf828526e5
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: free

void _ZN4hiai11HiaiIrBuild16ReleaseModelBuffERNS_15ModelBufferDataE(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 9 instructions
    /* 0x6b80 */ ldr x0, [x1];
    /* 0x6b84 */ str wzr, [x1, #8];
    /* 0x6b88 */ cbz x0, #0x6ba0;
    /* 0x6b8c */ stp x30, x19, [sp, #-0x10]!;
    /* 0x6b90 */ mov x19, x1;
    free();
    /* 0x6b98 */ str xzr, [x19];
    /* 0x6b9c */ ldp x30, x19, [sp], #0x10;
    return x0;
}
