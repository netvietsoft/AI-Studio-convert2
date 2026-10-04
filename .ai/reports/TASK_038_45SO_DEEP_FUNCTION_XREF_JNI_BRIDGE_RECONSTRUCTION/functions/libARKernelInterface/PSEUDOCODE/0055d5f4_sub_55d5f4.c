// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0x55d5f4
// Recovered Name: sub_55d5f4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x55d5f4 | Size: 20 bytes | SHA256: 7044b42070f410f527fdf9098d2005fa49297bfb9aad2b4dbb914d21844afdac
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: __android_log_print
// Strings referenced:
//   "arkernel"

void sub_55d5f4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 5 instructions
    /* 0x55d5f4 */ adrp x1, #0x1fc000;
    /* 0x55d5f8 */ add x1, x1, #0xe41;
    /* 0x55d5fc */ mov w0, #5;
    __android_log_print();
    /* 0x55d604 */ mov w0, #-1;
}
