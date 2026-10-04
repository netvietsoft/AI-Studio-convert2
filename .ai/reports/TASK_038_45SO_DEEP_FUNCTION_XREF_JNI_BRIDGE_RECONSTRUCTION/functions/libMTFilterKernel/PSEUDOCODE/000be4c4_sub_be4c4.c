// Library: libMTFilterKernel.so
// Function ID: libMTFilterKernel::0xbe4c4
// Recovered Name: sub_be4c4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xbe4c4 | Size: 204 bytes | SHA256: 61aac54b49fcff3db74ee8f646287da15af903a520741769b70de0bf3db7bae5
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: __android_log_print, __stack_chk_fail
// Strings referenced:
//   "ERROR: MTFilterKernel::FilterkernelNativeFace getFaceRect, faceData object is NULL"
//   "FilterKernel"

void sub_be4c4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 51 instructions
    /* 0xbe4c4 */ stp x29, x30, [sp, #0x20];
    /* 0xbe4c8 */ str x21, [sp, #0x30];
    /* 0xbe4cc */ stp x20, x19, [sp, #0x40];
    /* 0xbe4d0 */ add x29, sp, #0x20;
    /* 0xbe4d4 */ mrs x21, tpidr_el0;
    /* 0xbe4d8 */ ldr x8, [x21, #0x28];
    /* 0xbe4dc */ stur x8, [x29, #-8];
    /* 0xbe4e0 */ cbz x2, #0xbe540;
    /* 0xbe4e4 */ ldr w8, [x2];
    /* 0xbe4e8 */ cmp w8, w3;
    /* 0xbe4ec */ b.le #0xbe564;
    MTRTFILTERKERNEL_GetLogLevel();
    __android_log_print();
    return x0;
    __stack_chk_fail();
}
