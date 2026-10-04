// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a700
// Recovered Name: sub_56a700
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a700 | Size: 324 bytes | SHA256: 08c57c5997d8cb42465f2cb522ee1dc4b340aedfce9c258c53e811ef56a39571
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetFacialLandmark2DVisible(JI[F)V (table at 0x10cced8)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelFaceInterface::SetFacialLandmark2D: data len = %d , face point count = %d"
//   "arkernel"

jlong sub_56a700(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x56a700 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x56a704 */ str x23, [sp, #0x10];
    /* 0x56a708 */ stp x22, x21, [sp, #0x20];
    /* 0x56a70c */ stp x20, x19, [sp, #0x30];
    /* 0x56a710 */ mov x29, sp;
    /* 0x56a714 */ cbz x2, #0x56a830;
    /* 0x56a718 */ mov w22, w3;
    /* 0x56a71c */ cmp w3, #0x13;
    /* 0x56a720 */ b.hi #0x56a830;
    /* 0x56a724 */ ldr x8, [x0];
    /* 0x56a728 */ mov x1, x4;
    sub_5a6b20();
    memcpy();
    __android_log_print();
    return x0;
}
