// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58cd74
// Recovered Name: sub_58cd74
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58cd74 | Size: 268 bytes | SHA256: 99dd0e9b45e316ac07d757895fb25ed26fbe2a2e07929bd642546b0ab8fe1c9e
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeDisplay(JIIIII)V (table at 0x10d09e8)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "Not CPT_MakeupHairDaub Type"
//   "arkernel"

jlong sub_58cd74(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 67 instructions
    /* 0x58cd74 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x58cd78 */ stp x24, x23, [sp, #0x10];
    /* 0x58cd7c */ stp x22, x21, [sp, #0x20];
    /* 0x58cd80 */ stp x20, x19, [sp, #0x30];
    /* 0x58cd84 */ mov x29, sp;
    /* 0x58cd88 */ cbz x2, #0x58ce44;
    /* 0x58cd8c */ mov x0, x2;
    /* 0x58cd90 */ mov w19, w7;
    /* 0x58cd94 */ mov w20, w6;
    /* 0x58cd98 */ mov w21, w5;
    /* 0x58cd9c */ mov x24, x2;
    sub_8e0920();
    __dynamic_cast();
    return x0;
}
