// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55ef8c
// Recovered Name: sub_55ef8c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55ef8c | Size: 292 bytes | SHA256: 2c53c46109c070c3aaace5e777afbfc9172ca5b70a6178eb179cefb919c87027
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetLandmark2D(JI[F)V (table at 0x10cc290)
// Calls external APIs: __android_log_print, memcpy
// Strings referenced:
//   "ARKernelAnimalInterfaceJNI::SetLandmark2D: data len = %d , point count = %d"
//   "arkernel"

jlong sub_55ef8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 73 instructions
    /* 0x55ef8c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x55ef90 */ stp x22, x21, [sp, #0x10];
    /* 0x55ef94 */ stp x20, x19, [sp, #0x20];
    /* 0x55ef98 */ mov x29, sp;
    /* 0x55ef9c */ cbz x2, #0x55f0a0;
    /* 0x55efa0 */ mov w22, w3;
    /* 0x55efa4 */ cmp w3, #9;
    /* 0x55efa8 */ b.hi #0x55f0a0;
    /* 0x55efac */ ldr x8, [x0];
    /* 0x55efb0 */ mov x1, x4;
    /* 0x55efb4 */ mov x19, x4;
    sub_5a6b20();
    memcpy();
    __android_log_print();
    return x0;
}
