// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58caec
// Recovered Name: sub_58caec
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58caec | Size: 224 bytes | SHA256: cac9775e150608ff61d6f5df663dee0e6f5f4eb787720ae4c28816940af05bfc
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetTranslate(JII)V (table at 0x10d09b8)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

jlong sub_58caec(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x58caec */ stp x29, x30, [sp, #-0x30]!;
    /* 0x58caf0 */ str x21, [sp, #0x10];
    /* 0x58caf4 */ stp x20, x19, [sp, #0x20];
    /* 0x58caf8 */ mov x29, sp;
    /* 0x58cafc */ cbz x2, #0x58cb98;
    /* 0x58cb00 */ mov x0, x2;
    /* 0x58cb04 */ mov w19, w4;
    /* 0x58cb08 */ mov x21, x2;
    /* 0x58cb0c */ mov w20, w3;
    sub_8e0920();
    /* 0x58cb14 */ cmp w0, #0x6e;
    __dynamic_cast();
    return x0;
}
