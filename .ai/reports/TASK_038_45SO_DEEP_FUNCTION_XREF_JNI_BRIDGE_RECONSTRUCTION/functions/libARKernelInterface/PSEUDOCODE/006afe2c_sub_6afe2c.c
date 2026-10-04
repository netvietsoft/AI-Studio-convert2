// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x6afe2c
// Recovered Name: sub_6afe2c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6afe2c | Size: 336 bytes | SHA256: 237ef5ec50309d5851aff226ffb903b4f336f829f082ab6bd2ee279e93300755
// Callers: 1 | Callees: 11 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"
//   "segment mask not yet prepared"

void sub_6afe2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 84 instructions
    /* 0x6afe2c */ stp x29, x30, [sp, #-0x40]!;
    /* 0x6afe30 */ str x23, [sp, #0x10];
    /* 0x6afe34 */ stp x22, x21, [sp, #0x20];
    /* 0x6afe38 */ stp x20, x19, [sp, #0x30];
    /* 0x6afe3c */ mov x29, sp;
    /* 0x6afe40 */ mov x19, x0;
    /* 0x6afe44 */ ldr x0, [x0, #0x108];
    /* 0x6afe48 */ mov w20, w1;
    sub_c38b3c();
    /* 0x6afe50 */ cbz x0, #0x6afe60;
    /* 0x6afe54 */ mov x21, x0;
    sub_69b7c4();
    sub_c39340();
    sub_c38b3c();
    sub_69b7c4();
    sub_69b7c4();
    sub_69b7cc();
    sub_69b7d4();
    sub_da2fe4();
    sub_da2a50();
    sub_5a6b20();
    sub_da2568();
    sub_da2ed4();
    sub_d7ffbc();
    __android_log_print();
    return x0;
}
