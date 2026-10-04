// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x56e084
// Recovered Name: sub_56e084
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x56e084 | Size: 128 bytes | SHA256: d78dca1cf8b7dea3ff417806e99b52c123b1e8cc43d15b0c10170887d5b5fb5c
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nativeSetInternalLogLevel(I)V (table at 0x10cd460)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "ARKernelGlobalInterfaceJNI::SetInternalLogLevel: level = %d"
//   "arkernel"

jlong sub_56e084(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0x56e084 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x56e088 */ str x19, [sp, #0x10];
    /* 0x56e08c */ mov x29, sp;
    /* 0x56e090 */ adrp x8, #0x10c5000;
    /* 0x56e094 */ mov w19, w2;
    /* 0x56e098 */ ldr x8, [x8, #0x7a8];
    /* 0x56e09c */ ldr w8, [x8];
    /* 0x56e0a0 */ cmp w8, #2;
    /* 0x56e0a4 */ b.gt #0x56e0f4;
    /* 0x56e0a8 */ adrp x8, #0x1108000;
    /* 0x56e0ac */ add x8, x8, #0x8f8;
    sub_5a6b20();
    __android_log_print();
}
