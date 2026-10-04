// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58dee8
// Recovered Name: sub_58dee8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58dee8 | Size: 204 bytes | SHA256: f30e1fbf7568512a463381e57d52cd0ccb8410a56a6b608a282ceec86d8cd529
// Callers: 0 | Callees: 4 | Imports: 2

// Dynamic Registration: nativeGetIsGlobalFilter(J)Z (table at 0x10d0b50)
// Calls external APIs: __android_log_print, __dynamic_cast
// Strings referenced:
//   "GetIsGlobalFilter"
//   "arkernel"

jlong sub_58dee8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0x58dee8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58deec */ str x19, [sp, #0x10];
    /* 0x58def0 */ mov x29, sp;
    /* 0x58def4 */ adrp x8, #0x10c5000;
    /* 0x58def8 */ mov x19, x2;
    /* 0x58defc */ ldr x8, [x8, #0x7a8];
    /* 0x58df00 */ ldr w8, [x8];
    /* 0x58df04 */ cmp w8, #2;
    /* 0x58df08 */ b.gt #0x58df34;
    /* 0x58df0c */ adrp x8, #0x10c5000;
    /* 0x58df10 */ ldr x8, [x8, #0x7c8];
    sub_5a6b20();
    sub_8e0920();
    __dynamic_cast();
    sub_9e1174();
    sub_9e1180();
    __android_log_print();
    return x0;
}
