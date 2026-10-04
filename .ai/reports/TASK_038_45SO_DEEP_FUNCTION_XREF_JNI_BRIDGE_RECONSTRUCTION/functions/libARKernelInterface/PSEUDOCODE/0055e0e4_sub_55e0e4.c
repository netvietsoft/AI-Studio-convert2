// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55e0e4
// Recovered Name: sub_55e0e4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x55e0e4 | Size: 152 bytes | SHA256: db345fec124511fcbb9efc8e8d5e1d2044150ee8aa1ab59232144132fbc94220
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetEnableMakeupAdapt(JZ)V (table at 0x10cc110)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelARAiStateInterfaceJNI::SetEnableMakeupAdapt: %d"
//   "arkernel"

jlong sub_55e0e4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 38 instructions
    /* 0x55e0e4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x55e0e8 */ stp x20, x19, [sp, #0x10];
    /* 0x55e0ec */ mov x29, sp;
    /* 0x55e0f0 */ adrp x8, #0x10c5000;
    /* 0x55e0f4 */ mov w19, w3;
    /* 0x55e0f8 */ mov x20, x2;
    /* 0x55e0fc */ ldr x8, [x8, #0x7a8];
    /* 0x55e100 */ ldr w8, [x8];
    /* 0x55e104 */ cmp w8, #2;
    /* 0x55e108 */ b.gt #0x55e140;
    /* 0x55e10c */ adrp x8, #0x10c5000;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
