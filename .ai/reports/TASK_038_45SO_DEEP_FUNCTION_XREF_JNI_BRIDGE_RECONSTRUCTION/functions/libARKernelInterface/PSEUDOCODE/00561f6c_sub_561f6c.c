// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x561f6c
// Recovered Name: sub_561f6c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x561f6c | Size: 292 bytes | SHA256: a47afd67fa6fd1f0bb6c831cb0c1f39946e4a73b3bc163784dd1c74970cc2063
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeGetContourScores(JI)[F (table at 0x10cc5f0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelBodyInterfaceJNI::GetBodyScores illegal index"
//   "arkernel"

jlong sub_561f6c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x561f6c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x561f70 */ stp x22, x21, [sp, #0x10];
    /* 0x561f74 */ stp x20, x19, [sp, #0x20];
    /* 0x561f78 */ mov x29, sp;
    /* 0x561f7c */ cbz x2, #0x562074;
    /* 0x561f80 */ tbnz w3, #0x1f, #0x562004;
    /* 0x561f84 */ ldr w8, [x2, #0xc];
    /* 0x561f88 */ cmp w8, w3;
    /* 0x561f8c */ b.le #0x562004;
    /* 0x561f90 */ mov w8, #0x770;
    /* 0x561f94 */ ldr x9, [x0];
    return x0;
    sub_5a6b20();
    __android_log_print();
}
