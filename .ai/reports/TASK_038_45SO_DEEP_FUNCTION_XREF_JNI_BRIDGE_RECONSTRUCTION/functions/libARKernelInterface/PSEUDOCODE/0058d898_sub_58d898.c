// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d898
// Recovered Name: sub_58d898
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58d898 | Size: 200 bytes | SHA256: 372905f83ff2b71736fae86529b239fdb385736357993731ec5fdc003e4ebd08
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetManualSlimming3Enable(JZ)V (table at 0x10d0ad8)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "SetManualSlimming3Enable: Not CPT_SlimV2 Type"
//   "arkernel"

jlong sub_58d898(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x58d898 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58d89c */ stp x20, x19, [sp, #0x10];
    /* 0x58d8a0 */ mov x29, sp;
    /* 0x58d8a4 */ cbz x2, #0x58d934;
    /* 0x58d8a8 */ mov x0, x2;
    /* 0x58d8ac */ mov x20, x2;
    /* 0x58d8b0 */ mov w19, w3;
    sub_8e0920();
    /* 0x58d8b8 */ cmp w0, #0x13e;
    /* 0x58d8bc */ b.ne #0x58d8f0;
    /* 0x58d8c0 */ adrp x1, #0x10c5000;
    __dynamic_cast();
    return x0;
}
