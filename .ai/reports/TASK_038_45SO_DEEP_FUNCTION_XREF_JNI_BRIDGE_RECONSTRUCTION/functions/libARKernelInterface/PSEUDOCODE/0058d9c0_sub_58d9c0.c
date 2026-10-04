// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d9c0
// Recovered Name: sub_58d9c0
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58d9c0 | Size: 156 bytes | SHA256: e112a444ccb9ed2f3ec5f29ccdb38f785fde9bb86752e66dbb947d2bb18866c5
// Callers: 0 | Callees: 2 | Imports: 1

// Dynamic Registration: nativeGetMUType(J)I (table at 0x10d0af0)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "Not CPT_STATIC Type"
//   "arkernel"

jlong sub_58d9c0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 39 instructions
    /* 0x58d9c0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58d9c4 */ str x19, [sp, #0x10];
    /* 0x58d9c8 */ mov x29, sp;
    /* 0x58d9cc */ cbz x2, #0x58da4c;
    /* 0x58d9d0 */ mov x0, x2;
    /* 0x58d9d4 */ mov x19, x2;
    sub_8e0920();
    /* 0x58d9dc */ cmp w0, #1;
    /* 0x58d9e0 */ b.ne #0x58d9f4;
    /* 0x58d9e4 */ mov x0, x19;
    /* 0x58d9e8 */ ldr x19, [sp, #0x10];
    sub_5a6b20();
    __android_log_print();
    return x0;
}
