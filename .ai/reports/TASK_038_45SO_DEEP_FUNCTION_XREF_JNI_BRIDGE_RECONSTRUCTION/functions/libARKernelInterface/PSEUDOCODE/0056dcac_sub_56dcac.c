// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56dcac
// Recovered Name: sub_56dcac
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56dcac | Size: 984 bytes | SHA256: 47346cc8a90300e3ae007c15ff997ff178d36f79d4fc7b7cbeef44d94396cc88
// Callers: 0 | Callees: 2 | Imports: 1

// Dynamic Registration: nativeSetApplicationContext(Landroid/content/Context;)V (table at 0x10cd448)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "()Ljava/lang/String;"
//   "ARKernelGlobalInterfaceJNI::Set Application Context: %p"
//   "arkernel"
//   "getPackageName"

jlong sub_56dcac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 246 instructions
    /* 0x56dcac */ stp x29, x30, [sp, #-0x50]!;
    /* 0x56dcb0 */ str x25, [sp, #0x10];
    /* 0x56dcb4 */ stp x24, x23, [sp, #0x20];
    /* 0x56dcb8 */ stp x22, x21, [sp, #0x30];
    /* 0x56dcbc */ stp x20, x19, [sp, #0x40];
    /* 0x56dcc0 */ mov x29, sp;
    /* 0x56dcc4 */ adrp x25, #0x10c5000;
    /* 0x56dcc8 */ mov x22, x2;
    /* 0x56dccc */ mov x19, x0;
    /* 0x56dcd0 */ ldr x25, [x25, #0x7a8];
    /* 0x56dcd4 */ ldr w8, [x25];
    sub_5a6b20();
    sub_55d634();
    sub_5a6b20();
    __android_log_print();
    return x0;
    sub_5a6b20();
    sub_5a6b20();
    __android_log_print();
    __android_log_print();
    __android_log_print();
}
