// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c950
// Recovered Name: sub_58c950
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c950 | Size: 196 bytes | SHA256: d6a5745a7cd2201c915ac00c68b4a1f7b5b9d628ad79cef8b03e536eb951841f
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetBrushSize(JI)V (table at 0x10d0970)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

jlong sub_58c950(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x58c950 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58c954 */ stp x20, x19, [sp, #0x10];
    /* 0x58c958 */ mov x29, sp;
    /* 0x58c95c */ cbz x2, #0x58c9e8;
    /* 0x58c960 */ mov x0, x2;
    /* 0x58c964 */ mov x20, x2;
    /* 0x58c968 */ mov w19, w3;
    sub_8e0920();
    /* 0x58c970 */ cmp w0, #0x6e;
    /* 0x58c974 */ b.ne #0x58c9a4;
    /* 0x58c978 */ adrp x1, #0x10c5000;
    __dynamic_cast();
    return x0;
}
