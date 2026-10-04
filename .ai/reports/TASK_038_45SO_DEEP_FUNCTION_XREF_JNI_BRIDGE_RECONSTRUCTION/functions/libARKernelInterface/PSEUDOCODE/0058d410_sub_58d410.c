// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d410
// Recovered Name: sub_58d410
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58d410 | Size: 196 bytes | SHA256: 65f5f387eb311366f49971e45719b8f2576c3358b1082b02e855369eb22ec425
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetEnableOption(JI)V (table at 0x10d0a60)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "SetEnableOption: Not CPT_SlimV2 Type"
//   "arkernel"

jlong sub_58d410(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x58d410 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58d414 */ stp x20, x19, [sp, #0x10];
    /* 0x58d418 */ mov x29, sp;
    /* 0x58d41c */ cbz x2, #0x58d4a8;
    /* 0x58d420 */ mov x0, x2;
    /* 0x58d424 */ mov x20, x2;
    /* 0x58d428 */ mov w19, w3;
    sub_8e0920();
    /* 0x58d430 */ cmp w0, #0x13e;
    /* 0x58d434 */ b.ne #0x58d464;
    /* 0x58d438 */ adrp x1, #0x10c5000;
    __dynamic_cast();
    return x0;
}
