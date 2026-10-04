// Library: libPVGLive.so
// Function ID: libPVGLive::0x713f8
// Recovered Name: sub_713f8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x713f8 | Size: 228 bytes | SHA256: 3c4b714d63201ea4e71610a1162eaadfb2a9e3a0517ed6c38060296ac0b6f322
// Callers: 2 | Callees: 2 | Imports: 3

// Calls external APIs: _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z, __android_log_print, pthread_self
// Strings referenced:
//   "F[%s, L(%d)], T(%p):> JpegEditor: failed to scan JPEG segments"
//   "parse"

void sub_713f8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 57 instructions
    /* 0x713f8 */ stp x29, x30, [sp, #-0x40]!;
    /* 0x713fc */ stp x24, x23, [sp, #0x10];
    /* 0x71400 */ stp x22, x21, [sp, #0x20];
    /* 0x71404 */ stp x20, x19, [sp, #0x30];
    /* 0x71408 */ mov x29, sp;
    /* 0x7140c */ mov x19, x2;
    /* 0x71410 */ mov x21, x1;
    /* 0x71414 */ mov x20, x0;
    /* 0x71418 */ stp x1, x2, [x0], #0x40;
    sub_2b2a0();
    /* 0x71420 */ add x2, x20, #0x18;
    sub_72ec4();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    return x0;
}
