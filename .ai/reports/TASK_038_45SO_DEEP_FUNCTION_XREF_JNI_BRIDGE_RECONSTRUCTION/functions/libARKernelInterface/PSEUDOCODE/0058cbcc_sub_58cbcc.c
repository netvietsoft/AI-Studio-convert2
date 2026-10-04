// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58cbcc
// Recovered Name: sub_58cbcc
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58cbcc | Size: 224 bytes | SHA256: e1eab9ad05773b14fa53efc75be3cff20260eb6daf5d0b3a317738025b816b55
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeAddTranslate(JII)V (table at 0x10d09d0)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

jlong sub_58cbcc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 56 instructions
    /* 0x58cbcc */ stp x29, x30, [sp, #-0x30]!;
    /* 0x58cbd0 */ str x21, [sp, #0x10];
    /* 0x58cbd4 */ stp x20, x19, [sp, #0x20];
    /* 0x58cbd8 */ mov x29, sp;
    /* 0x58cbdc */ cbz x2, #0x58cc78;
    /* 0x58cbe0 */ mov x0, x2;
    /* 0x58cbe4 */ mov w19, w4;
    /* 0x58cbe8 */ mov x21, x2;
    /* 0x58cbec */ mov w20, w3;
    sub_8e0920();
    /* 0x58cbf4 */ cmp w0, #0x6e;
    __dynamic_cast();
    return x0;
}
