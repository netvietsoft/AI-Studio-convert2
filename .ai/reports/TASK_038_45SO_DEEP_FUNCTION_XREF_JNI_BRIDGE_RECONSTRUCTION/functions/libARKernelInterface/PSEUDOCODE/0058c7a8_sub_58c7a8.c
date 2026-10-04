// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x58c7a8
// Recovered Name: sub_58c7a8
// Visibility: REGISTER_NATIVES_TARGET | Confidence: FACT
// Address: 0x58c7a8 | Size: 132 bytes | SHA256: 3cf64fd447cad9d4c3f6a8690e72c6c2f2adb172ec2e7fd0dbd339247ae036b2
// Callers: 0 | Callees: 1 | Imports: 1

// Dynamic Registration: nHaveColor(J)Z (table at 0x10d0940)
// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"
//   "makeupcolor HaveColor"

jlong sub_58c7a8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 33 instructions
    /* 0x58c7a8 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x58c7ac */ str x19, [sp, #0x10];
    /* 0x58c7b0 */ mov x29, sp;
    /* 0x58c7b4 */ adrp x8, #0x10c5000;
    /* 0x58c7b8 */ mov x19, x2;
    /* 0x58c7bc */ ldr x8, [x8, #0x7a8];
    /* 0x58c7c0 */ ldr w8, [x8];
    /* 0x58c7c4 */ cmp w8, #2;
    /* 0x58c7c8 */ b.gt #0x58c7f4;
    /* 0x58c7cc */ adrp x8, #0x1108000;
    /* 0x58c7d0 */ add x8, x8, #0x8f8;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
