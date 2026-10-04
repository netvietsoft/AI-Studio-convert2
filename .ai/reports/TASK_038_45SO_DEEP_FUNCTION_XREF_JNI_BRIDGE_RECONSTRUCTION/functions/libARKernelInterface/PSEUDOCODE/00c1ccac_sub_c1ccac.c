// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc1ccac
// Recovered Name: sub_c1ccac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc1ccac | Size: 128 bytes | SHA256: 0e4b779d3a8f89e2ad1c0a864ac2d8fa5b6f7d40e677eaf0d20d8597248a1a49
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"
//   "error SetFaceHairMask"

void sub_c1ccac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 32 instructions
    /* 0xc1ccac */ cmp w1, #0x14;
    /* 0xc1ccb0 */ b.hi #0xc1ccd4;
    /* 0xc1ccb4 */ orr w8, w4, w3;
    /* 0xc1ccb8 */ tbnz w8, #0x1f, #0xc1ccd4;
    /* 0xc1ccbc */ add x8, x0, w1, uxtw #2;
    /* 0xc1ccc0 */ add x9, x0, w1, uxtw #3;
    /* 0xc1ccc4 */ str w3, [x8, #0x1d88];
    /* 0xc1ccc8 */ str w4, [x8, #0x1dd8];
    /* 0xc1cccc */ str x2, [x9, #0x1ce8];
    /* 0xc1ccd0 */ b #0xc1cd10;
    /* 0xc1ccd4 */ adrp x8, #0x10d0000;
    return x0;
}
