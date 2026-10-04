// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc1cb50
// Recovered Name: sub_c1cb50
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc1cb50 | Size: 348 bytes | SHA256: 6640a6ebc4825eacf282f4db5b853e5ac24a06cf9d75fce1720b51e8c25ce913
// Callers: 1 | Callees: 0 | Imports: 5

// Calls external APIs: _ZdaPv, _Znam, __android_log_print, memcpy, memset
// Strings referenced:
//   "arkernel"
//   "error SetSegmentEyePupilMask"

void sub_c1cb50(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 87 instructions
    /* 0xc1cb50 */ stp x29, x30, [sp, #-0x40]!;
    /* 0xc1cb54 */ str x23, [sp, #0x10];
    /* 0xc1cb58 */ stp x22, x21, [sp, #0x20];
    /* 0xc1cb5c */ stp x20, x19, [sp, #0x30];
    /* 0xc1cb60 */ mov x29, sp;
    /* 0xc1cb64 */ cmp w1, #0x14;
    /* 0xc1cb68 */ b.hi #0xc1cc08;
    /* 0xc1cb6c */ mov w20, w6;
    /* 0xc1cb70 */ mov w21, w5;
    /* 0xc1cb74 */ orr w8, w6, w5;
    /* 0xc1cb78 */ tbnz w8, #0x1f, #0xc1cc08;
    _ZdaPv();
    _Znam();
    return x0;
}
