// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc38b3c
// Recovered Name: sub_c38b3c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc38b3c | Size: 536 bytes | SHA256: a8cf85137e242aadd8d247a612b41e0e584f6fb4e9baf5cd8ed9985852d5a7f6
// Callers: 54 | Callees: 7 | Imports: 3

// Calls external APIs: _ZNSt6__ndk15mutex4lockEv, _ZNSt6__ndk15mutex6unlockEv, __android_log_print
// Strings referenced:
//   "SegmentService::GetSegmentMask: the segment mask is invalid !"
//   "arkernel"

void sub_c38b3c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 134 instructions
    /* 0xc38b3c */ stp x29, x30, [sp, #-0x30]!;
    /* 0xc38b40 */ str x21, [sp, #0x10];
    /* 0xc38b44 */ stp x20, x19, [sp, #0x20];
    /* 0xc38b48 */ mov x29, sp;
    /* 0xc38b4c */ mov x19, x0;
    /* 0xc38b50 */ add x0, x0, #0x1b8;
    /* 0xc38b54 */ mov w21, w1;
    _ZNSt6__ndk15mutex4lockEv();
    /* 0xc38b5c */ cmp w21, #0x1b;
    /* 0xc38b60 */ b.hi #0xc38cdc;
    /* 0xc38b64 */ mov w8, w21;
    sub_c378ec();
    sub_c3a7c4();
    sub_69add8();
    sub_c39384();
    sub_c3a7c4();
    sub_c3acfc();
    sub_c3af64();
    sub_c3acfc();
    sub_c3af64();
    sub_69add8();
    sub_5a6b20();
    __android_log_print();
    _ZNSt6__ndk15mutex6unlockEv();
    return x0;
}
