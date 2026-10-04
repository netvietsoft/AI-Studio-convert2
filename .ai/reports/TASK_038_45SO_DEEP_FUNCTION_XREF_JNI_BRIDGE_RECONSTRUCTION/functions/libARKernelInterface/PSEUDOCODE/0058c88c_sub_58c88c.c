// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c88c
// Recovered Name: sub_58c88c
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c88c | Size: 196 bytes | SHA256: 302c194549c4baa1305150d767bcc64ee20f92fe3a2a220516a345fc42286242
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetDaubModel(JI)V (table at 0x10d0958)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

jlong sub_58c88c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x58c88c */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58c890 */ stp x20, x19, [sp, #0x10];
    /* 0x58c894 */ mov x29, sp;
    /* 0x58c898 */ cbz x2, #0x58c924;
    /* 0x58c89c */ mov x0, x2;
    /* 0x58c8a0 */ mov x20, x2;
    /* 0x58c8a4 */ mov w19, w3;
    sub_8e0920();
    /* 0x58c8ac */ cmp w0, #0x6e;
    /* 0x58c8b0 */ b.ne #0x58c8e0;
    /* 0x58c8b4 */ adrp x1, #0x10c5000;
    __dynamic_cast();
    return x0;
}
