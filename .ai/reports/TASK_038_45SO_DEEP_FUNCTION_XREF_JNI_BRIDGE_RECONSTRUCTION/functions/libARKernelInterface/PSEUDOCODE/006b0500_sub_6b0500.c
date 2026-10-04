// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x6b0500
// Recovered Name: sub_6b0500
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6b0500 | Size: 444 bytes | SHA256: e332f0c05ccb0f4c579d47e72e39802907014ae17366d4248cf09c6a85b5a289
// Callers: 1 | Callees: 11 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "The number of requested face indexes is greater than the actual number of faces"
//   "arkernel"
//   "face hair mask not yet prepared"

void sub_6b0500(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 111 instructions
    /* 0x6b0500 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x6b0504 */ str x23, [sp, #0x10];
    /* 0x6b0508 */ stp x22, x21, [sp, #0x20];
    /* 0x6b050c */ stp x20, x19, [sp, #0x30];
    /* 0x6b0510 */ mov x29, sp;
    /* 0x6b0514 */ ldr x8, [x0, #0x2d0];
    /* 0x6b0518 */ ldr x9, [x0, #0x2c8];
    /* 0x6b051c */ sub x8, x8, x9;
    /* 0x6b0520 */ mov x9, #-0x5555555555555556;
    /* 0x6b0524 */ asr x8, x8, #3;
    /* 0x6b0528 */ movk x9, #0xaaab;
    sub_c18354();
    sub_69b7c4();
    sub_69b7c4();
    sub_69b7cc();
    sub_69b7d4();
    sub_da2fe4();
    sub_da2a50();
    sub_da2fd0();
    sub_5a6b20();
    sub_da2568();
    sub_da2ed4();
    sub_da2fd0();
    sub_d7ffbc();
    __android_log_print();
    return x0;
}
