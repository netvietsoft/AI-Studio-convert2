// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xc06cc
// Recovered Name: _ZN20MTFilterKernelRender32setBodySegmentDataWithBytebufferEP7_JNIEnvP8_jobjectlS3_iiii
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0xc06cc | Size: 168 bytes | SHA256: b114860041804fc4a5883ded822447526783fd2bc72de90be4e4b8a3e6eaaa7a
// Callers: 0 | Callees: 0 | Imports: 0

// Dynamic Registration: nSetBodySegmentDataWithBytebuffer(JLjava/nio/ByteBuffer;IIII)V (table at 0x1ca698)

jlong _ZN20MTFilterKernelRender32setBodySegmentDataWithBytebufferEP7_JNIEnvP8_jobjectlS3_iiii(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 42 instructions
    /* 0xc06cc */ stp x29, x30, [sp, #-0x40]!;
    /* 0xc06d0 */ str x23, [sp, #0x10];
    /* 0xc06d4 */ stp x22, x21, [sp, #0x20];
    /* 0xc06d8 */ stp x20, x19, [sp, #0x30];
    /* 0xc06dc */ mov x29, sp;
    /* 0xc06e0 */ cbz x2, #0xc0738;
    /* 0xc06e4 */ mov x22, x2;
    /* 0xc06e8 */ cbz x3, #0xc074c;
    /* 0xc06ec */ ldr x8, [x0];
    /* 0xc06f0 */ mov x1, x3;
    /* 0xc06f4 */ mov w19, w7;
    return x0;
}
