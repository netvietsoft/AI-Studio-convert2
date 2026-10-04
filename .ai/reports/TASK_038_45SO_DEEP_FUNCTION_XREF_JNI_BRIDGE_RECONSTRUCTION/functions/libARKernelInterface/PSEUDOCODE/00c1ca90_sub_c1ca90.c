// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc1ca90
// Recovered Name: sub_c1ca90
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc1ca90 | Size: 192 bytes | SHA256: 8e58f1b8fa54c4095700fc99694eb7d15f2c4a3aed8e6370367d06bf33dbe984
// Callers: 1 | Callees: 1 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"
//   "error GetSegmentLeftEyePupilMask!"

void sub_c1ca90(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0xc1ca90 */ stp x29, x30, [sp, #-0x10]!;
    /* 0xc1ca94 */ mov x29, sp;
    /* 0xc1ca98 */ cmp w1, #0x15;
    /* 0xc1ca9c */ b.lo #0xc1cae0;
    /* 0xc1caa0 */ adrp x8, #0x10d0000;
    /* 0xc1caa4 */ add x8, x8, #0xc30;
    /* 0xc1caa8 */ ldr w8, [x8];
    /* 0xc1caac */ cmp w8, #5;
    /* 0xc1cab0 */ b.gt #0xc1cb44;
    /* 0xc1cab4 */ adrp x8, #0x1108000;
    /* 0xc1cab8 */ add x8, x8, #0x8f8;
    sub_5a6b20();
    __android_log_print();
    return x0;
}
