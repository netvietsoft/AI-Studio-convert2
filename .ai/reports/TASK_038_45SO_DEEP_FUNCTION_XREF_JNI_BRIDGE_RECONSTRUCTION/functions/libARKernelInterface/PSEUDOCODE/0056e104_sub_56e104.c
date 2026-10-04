// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e104
// Recovered Name: sub_56e104
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e104 | Size: 212 bytes | SHA256: 871db87ff560054019302a32c426174afe2dd80570b1bd38c834731880499e02
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetLogCallback(Lcom/meitu/mtlab/arkernelinterface/callback/ARKernelLogCallback;)V (table at 0x10cd478)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelGlobalInterfaceJNI::SetLogCallback"
//   "arkernel"

jlong sub_56e104(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0x56e104 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x56e108 */ str x21, [sp, #0x10];
    /* 0x56e10c */ stp x20, x19, [sp, #0x20];
    /* 0x56e110 */ mov x29, sp;
    /* 0x56e114 */ adrp x8, #0x10c5000;
    /* 0x56e118 */ mov x19, x2;
    /* 0x56e11c */ mov x20, x0;
    /* 0x56e120 */ ldr x8, [x8, #0x7a8];
    /* 0x56e124 */ ldr w8, [x8];
    /* 0x56e128 */ cmp w8, #2;
    /* 0x56e12c */ b.gt #0x56e174;
    sub_5a6b20();
    __android_log_print();
}
