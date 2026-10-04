// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56af00
// Recovered Name: sub_56af00
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56af00 | Size: 292 bytes | SHA256: 199028ecd52e40767b338867bbe8eddbf2303d7af31b492b70b245f41f0ff8d7
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetHeadPoints(JI[F)V (table at 0x10cd088)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelFaceInterface::SetHeadPoints: data len = %d , head point count = %d"
//   "arkernel"

jlong sub_56af00(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x56af00 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x56af04 */ stp x22, x21, [sp, #0x10];
    /* 0x56af08 */ stp x20, x19, [sp, #0x20];
    /* 0x56af0c */ mov x29, sp;
    /* 0x56af10 */ cbz x2, #0x56b014;
    /* 0x56af14 */ mov w22, w3;
    /* 0x56af18 */ cmp w3, #0x13;
    /* 0x56af1c */ b.hi #0x56b014;
    /* 0x56af20 */ ldr x8, [x0];
    /* 0x56af24 */ mov x1, x4;
    /* 0x56af28 */ mov x19, x4;
    sub_5a6b20();
    memcpy();
    __android_log_print();
    return x0;
}
