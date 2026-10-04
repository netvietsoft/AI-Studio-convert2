// Library: libARSPM.so
// Function ID: libARSPM::0x2e67ac
// Recovered Name: sub_2e67ac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x2e67ac | Size: 884 bytes | SHA256: ca0b38cef22d7320f2df419c7d0449c5c5d3ea7669b69af61837897522860eba
// Callers: 0 | Callees: 16 | Imports: 3

// Calls external APIs: __cxa_atexit, __cxa_guard_acquire, __cxa_guard_release
// Strings referenced:
//   "../../../../src/core/SkRuntimeEffectPriv.h"
//   "PTO"
//   "RRectBlur"
//   "blurRadius"
//   "cornerRadius"

void sub_2e67ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 221 instructions
    /* 0x2e67ac */ sub x8, x29, #0xe0;
    /* 0x2e67b0 */ sub x0, x29, #0x90;
    /* 0x2e67b4 */ add x2, sp, #0xd0;
    /* 0x2e67b8 */ mov w1, #2;
    /* 0x2e67bc */ mov w3, wzr;
    /* 0x2e67c0 */ mov w4, wzr;
    sub_331af0();
    /* 0x2e67c8 */ ldur x20, [x29, #-0x90];
    /* 0x2e67cc */ cbz x20, #0x2e67f4;
    /* 0x2e67d0 */ add x1, x20, #8;
    /* 0x2e67d4 */ mov w0, #-1;
    sub_4ecb10();
    sub_4ecb10();
    sub_4ecb10();
    sub_14803c();
    sub_148054();
    sub_2666f8();
    sub_2e6ef8();
    sub_327904();
    __cxa_guard_acquire();
    sub_3f2320();
    __cxa_guard_release();
    __cxa_guard_acquire();
    sub_1d8fb8();
    sub_1bdbb4();
    sub_1d93f8();
    sub_1d93f8();
    sub_4ecb10();
    __cxa_guard_release();
    sub_1df698();
    sub_15e650();
    __cxa_guard_acquire();
    sub_1da608();
    __cxa_atexit();
    __cxa_guard_release();
    sub_2cfaa0();
    sub_2666c0();
}
