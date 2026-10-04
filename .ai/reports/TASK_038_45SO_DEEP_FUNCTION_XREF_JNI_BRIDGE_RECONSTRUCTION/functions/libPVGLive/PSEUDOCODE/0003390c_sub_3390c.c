// Library: libPVGLive.so
// Function ID: libPVGLive::0x3390c
// Recovered Name: sub_3390c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3390c | Size: 1204 bytes | SHA256: c97e17704df1b8d0eeff02381f74b967391c05dbc58859f9b7269bb6f2665567
// Callers: 0 | Callees: 0 | Imports: 4

// Calls external APIs: _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z, _ZdlPv, __android_log_print, pthread_self
// Strings referenced:
//   "F[%s, L(%d)], T(%p):> MpfTransform::fixup: MPEntry tag (0xB002) not found"
//   "F[%s, L(%d)], T(%p):> MpfTransform::fixup: MPF segment not found in output"
//   "F[%s, L(%d)], T(%p):> MpfTransform::fixup: primarySize=%zu, gainMapSize=%zu, secondaryOffset=%zu (mpfMarkerPos=%zu, tiffBase=%zu)"
//   "F[%s, L(%d)], T(%p):> MpfTransform::fixup: unknown MPF byte order"
//   "fixup"

void sub_3390c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 301 instructions
    /* 0x3390c */ stp x29, x30, [sp, #0x30];
    /* 0x33910 */ stp x28, x27, [sp, #0x40];
    /* 0x33914 */ stp x26, x25, [sp, #0x50];
    /* 0x33918 */ stp x24, x23, [sp, #0x60];
    /* 0x3391c */ stp x22, x21, [sp, #0x70];
    /* 0x33920 */ stp x20, x19, [sp, #0x80];
    /* 0x33924 */ add x29, sp, #0x30;
    /* 0x33928 */ ldp x8, x9, [x0];
    /* 0x3392c */ mov x19, x1;
    /* 0x33930 */ mov x20, x0;
    /* 0x33934 */ sub x9, x9, x8;
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    return x0;
    return x0;
    pthread_self();
    __android_log_print();
    pthread_self();
    __android_log_print();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
    return x0;
}
