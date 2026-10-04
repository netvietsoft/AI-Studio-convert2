// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc1aa08
// Recovered Name: sub_c1aa08
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc1aa08 | Size: 336 bytes | SHA256: 3325a5514681bd34ee193b27a023847ff9ae052c9edfd6bf31d56837ceb139d1
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "SetSegmentMouthMask:size not match:nMaskSize:(%d,%d), MatrixSize:(%d,%d)"
//   "arkernel"

void sub_c1aa08(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 84 instructions
    /* 0xc1aa08 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xc1aa0c */ stp x24, x23, [sp, #0x10];
    /* 0xc1aa10 */ stp x22, x21, [sp, #0x20];
    /* 0xc1aa14 */ stp x20, x19, [sp, #0x30];
    /* 0xc1aa18 */ mov x29, sp;
    /* 0xc1aa1c */ ldr x23, [x29, #0x48];
    /* 0xc1aa20 */ sxtw x24, w1;
    /* 0xc1aa24 */ strb w2, [x23, w1, sxtw];
    /* 0xc1aa28 */ tbz w2, #0, #0xc1aa70;
    /* 0xc1aa2c */ mov x20, x3;
    /* 0xc1aa30 */ cbz x3, #0xc1aa84;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
