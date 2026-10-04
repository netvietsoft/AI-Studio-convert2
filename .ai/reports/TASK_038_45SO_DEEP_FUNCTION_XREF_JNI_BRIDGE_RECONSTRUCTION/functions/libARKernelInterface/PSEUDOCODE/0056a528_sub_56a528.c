// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56a528
// Recovered Name: sub_56a528
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56a528 | Size: 324 bytes | SHA256: 55f6fb6fb644801f6d3841a36bd5c9bc43e93f97a97bbff283f7122fe58d47f2
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetFacialLandmark2D(JI[F)V (table at 0x10ccea8)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelFaceInterface::SetFacialLandmark2D: data len = %d , face point count = %d"
//   "arkernel"

jlong sub_56a528(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 81 instructions
    /* 0x56a528 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x56a52c */ str x23, [sp, #0x10];
    /* 0x56a530 */ stp x22, x21, [sp, #0x20];
    /* 0x56a534 */ stp x20, x19, [sp, #0x30];
    /* 0x56a538 */ mov x29, sp;
    /* 0x56a53c */ cbz x2, #0x56a658;
    /* 0x56a540 */ mov w22, w3;
    /* 0x56a544 */ cmp w3, #0x13;
    /* 0x56a548 */ b.hi #0x56a658;
    /* 0x56a54c */ ldr x8, [x0];
    /* 0x56a550 */ mov x1, x4;
    sub_5a6b20();
    memcpy();
    __android_log_print();
    return x0;
}
