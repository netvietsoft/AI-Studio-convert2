// Library: libARKernelInterface.so
// Function ID: libARKernelInterface::0xc3ad2c
// Recovered Name: sub_c3ad2c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc3ad2c | Size: 568 bytes | SHA256: 7f12bce7f943380cb384de2ab536dd9fbf02a2692003c540b7dc78c2cea0a5b3
// Callers: 2 | Callees: 5 | Imports: 3

// Calls external APIs: _Znwm, __android_log_print, memset
// Strings referenced:
//   "UnifiedChannelSegmentMask::UnifiedChannel origin mask invalid!"
//   "arkernel"

void sub_c3ad2c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 142 instructions
    /* 0xc3ad2c */ stp x29, x30, [sp, #-0x40]!;
    /* 0xc3ad30 */ str x23, [sp, #0x10];
    /* 0xc3ad34 */ stp x22, x21, [sp, #0x20];
    /* 0xc3ad38 */ stp x20, x19, [sp, #0x30];
    /* 0xc3ad3c */ mov x29, sp;
    /* 0xc3ad40 */ ldrb w8, [x0, #0x1b0];
    /* 0xc3ad44 */ cbz w8, #0xc3af28;
    /* 0xc3ad48 */ ldr x8, [x0, #0x1b8];
    /* 0xc3ad4c */ mov x19, x0;
    /* 0xc3ad50 */ strb wzr, [x0, #0x1b0];
    /* 0xc3ad54 */ cbnz x8, #0xc3adac;
    _Znwm();
    memset();
    sub_69c424();
    sub_69add8();
    sub_69b7cc();
    sub_69b7d4();
    sub_69b7c4();
    sub_69b7cc();
    sub_69b7d4();
    sub_69b7c4();
    sub_69b7cc();
    sub_69b7d4();
    return x0;
}
