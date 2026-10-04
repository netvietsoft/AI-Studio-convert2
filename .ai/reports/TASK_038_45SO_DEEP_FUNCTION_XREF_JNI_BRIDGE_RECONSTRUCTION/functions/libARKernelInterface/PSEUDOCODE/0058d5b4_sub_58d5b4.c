// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58d5b4
// Recovered Name: sub_58d5b4
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58d5b4 | Size: 200 bytes | SHA256: fad0c2e1f45eb6990ee982256af876ff55fe72e1a63ff007fb5271caecae2c25
// Callers: 0 | Callees: 1 | Imports: 2

// Dynamic Registration: nativeSetManualLongLegEnable(JZ)V (table at 0x10d0a90)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "SetManualLongLegEnable: Not CPT_SlimV2 Type"
//   "arkernel"

jlong sub_58d5b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 50 instructions
    /* 0x58d5b4 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58d5b8 */ stp x20, x19, [sp, #0x10];
    /* 0x58d5bc */ mov x29, sp;
    /* 0x58d5c0 */ cbz x2, #0x58d650;
    /* 0x58d5c4 */ mov x0, x2;
    /* 0x58d5c8 */ mov x20, x2;
    /* 0x58d5cc */ mov w19, w3;
    sub_8e0920();
    /* 0x58d5d4 */ cmp w0, #0x13e;
    /* 0x58d5d8 */ b.ne #0x58d60c;
    /* 0x58d5dc */ adrp x1, #0x10c5000;
    __dynamic_cast();
    return x0;
}
