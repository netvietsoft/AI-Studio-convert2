// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55e1a8
// Recovered Name: sub_55e1a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55e1a8 | Size: 152 bytes | SHA256: 24fedc6637571b06277cd82b0bbb8e951d5a3d1614ee8c98e63a82119b5b84cb
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetEnableQNN(JZ)V (table at 0x10cc140)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelARAiStateInterfaceJNI::SetEnableQNN: %d"
//   "arkernel"

jlong sub_55e1a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x55e1a8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x55e1ac */ stp x20, x19, [sp, #0x10];
    /* 0x55e1b0 */ mov x29, sp;
    /* 0x55e1b4 */ adrp x8, #0x10c5000;
    /* 0x55e1b8 */ mov w19, w3;
    /* 0x55e1bc */ mov x20, x2;
    /* 0x55e1c0 */ ldr x8, [x8, #0x7a8];
    /* 0x55e1c4 */ ldr w8, [x8];
    /* 0x55e1c8 */ cmp w8, #2;
    /* 0x55e1cc */ b.gt #0x55e204;
    /* 0x55e1d0 */ adrp x8, #0x10c5000;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
