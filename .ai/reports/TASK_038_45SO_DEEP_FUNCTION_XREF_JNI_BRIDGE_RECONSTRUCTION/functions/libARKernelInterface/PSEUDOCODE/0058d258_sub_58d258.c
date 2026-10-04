// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d258
// Recovered Name: sub_58d258
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58d258 | Size: 260 bytes | SHA256: 3dc4c32d03f8c2f3a5e11fc341462ca93825bdbe655d0d7592961794cd8b1ea3
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeGetTransformationPoint(J[FI)V (table at 0x10d0a30)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "GetTransformationPoint: Not CPT_SlimV2 Type"
//   "arkernel"

jlong sub_58d258(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 65 instructions
    /* 0x58d258 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x58d25c */ stp x22, x21, [sp, #0x10];
    /* 0x58d260 */ stp x20, x19, [sp, #0x20];
    /* 0x58d264 */ mov x29, sp;
    /* 0x58d268 */ cbz x2, #0x58d328;
    /* 0x58d26c */ mov x22, x0;
    /* 0x58d270 */ mov x0, x2;
    /* 0x58d274 */ mov w19, w4;
    /* 0x58d278 */ mov x20, x3;
    /* 0x58d27c */ mov x21, x2;
    sub_8e0920();
    __dynamic_cast();
    return x0;
}
