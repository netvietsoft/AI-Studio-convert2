// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x57c328
// Recovered Name: sub_57c328
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x57c328 | Size: 304 bytes | SHA256: 452d86a58150ee0cf8eac1262052f30476f46820166cac8ebbd5f6342f3344f0
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetLandmark2D(JI[F)V (table at 0x10cea98)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelShoulderInterfaceJNI::SetLandmark2D: data len = %d , point count = %d"
//   "arkernel"

jlong sub_57c328(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 76 instructions
    /* 0x57c328 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x57c32c */ stp x22, x21, [sp, #0x10];
    /* 0x57c330 */ stp x20, x19, [sp, #0x20];
    /* 0x57c334 */ mov x29, sp;
    /* 0x57c338 */ cbz x2, #0x57c448;
    /* 0x57c33c */ mov w22, w3;
    /* 0x57c340 */ cmp w3, #9;
    /* 0x57c344 */ b.hi #0x57c448;
    /* 0x57c348 */ ldr x8, [x0];
    /* 0x57c34c */ mov x1, x4;
    /* 0x57c350 */ mov x19, x4;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
