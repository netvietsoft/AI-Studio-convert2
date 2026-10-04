// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56b27c
// Recovered Name: sub_56b27c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56b27c | Size: 284 bytes | SHA256: 4d594e410dd6352382e535555b5ca369b94d88e08169a63cd96ee67815fa3e31
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetFaceEmotionFactor(JI[F)V (table at 0x10cd1a8)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelFaceInterface::SetFaceEmotionFactor: data len = %d , emotion size count = %d"
//   "arkernel"

jlong sub_56b27c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 71 instructions
    /* 0x56b27c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x56b280 */ stp x22, x21, [sp, #0x10];
    /* 0x56b284 */ stp x20, x19, [sp, #0x20];
    /* 0x56b288 */ mov x29, sp;
    /* 0x56b28c */ cbz x2, #0x56b388;
    /* 0x56b290 */ mov w22, w3;
    /* 0x56b294 */ cmp w3, #0x13;
    /* 0x56b298 */ b.hi #0x56b388;
    /* 0x56b29c */ ldr x8, [x0];
    /* 0x56b2a0 */ mov x1, x4;
    /* 0x56b2a4 */ mov x19, x4;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
