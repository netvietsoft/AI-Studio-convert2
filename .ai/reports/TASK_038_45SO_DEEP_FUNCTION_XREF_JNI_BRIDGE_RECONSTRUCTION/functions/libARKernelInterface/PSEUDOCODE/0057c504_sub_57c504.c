// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c504
// Recovered Name: sub_57c504
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c504 | Size: 292 bytes | SHA256: 2202800168d9d60f3aa9b2cd92673e80af97144e6a6c4c98eb78950672d7a75a
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetScores(JI[F)V (table at 0x10ceac8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelShoulderInterfaceJNI::SetScores: data len = %d , point count = %d"
//   "arkernel"

jlong sub_57c504(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x57c504 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57c508 */ stp x22, x21, [sp, #0x10];
    /* 0x57c50c */ stp x20, x19, [sp, #0x20];
    /* 0x57c510 */ mov x29, sp;
    /* 0x57c514 */ cbz x2, #0x57c618;
    /* 0x57c518 */ mov w22, w3;
    /* 0x57c51c */ cmp w3, #9;
    /* 0x57c520 */ b.hi #0x57c618;
    /* 0x57c524 */ ldr x8, [x0];
    /* 0x57c528 */ mov x1, x4;
    /* 0x57c52c */ mov x19, x4;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
