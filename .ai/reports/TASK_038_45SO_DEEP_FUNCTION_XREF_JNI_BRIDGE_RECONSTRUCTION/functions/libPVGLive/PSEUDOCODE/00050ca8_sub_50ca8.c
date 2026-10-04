// Library: libPVGLive.so
// Function ID: libPVGLive::0x50ca8
// Recovered Name: sub_50ca8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x50ca8 | Size: 684 bytes | SHA256: c7d0d68eddd2b0307fc871700eacecee611aae0ccaf88f67a593dacfe8af2036
// Callers: 0 | Callees: 2 | Imports: 5

// Calls external APIs: _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z, _ZdlPv, __android_log_print, __stack_chk_fail, pthread_self
// Strings referenced:
//   "F[%s, L(%d)], T(%p):> Decoder extractVideo: applied video orientation patch (track=%u, targetOrientation=%d, segments=%zu)"
//   "F[%s, L(%d)], T(%p):> Decoder pre-rotated segment build failed: %s"
//   "PVGLive"
//   "prepareExtractedVideoRotation"

void sub_50ca8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 171 instructions
    /* 0x50ca8 */ ldur x0, [x29, #-0x100];
    /* 0x50cac */ cbz x0, #0x50cb8;
    /* 0x50cb0 */ stur x0, [x29, #-0xf8];
    _ZdlPv();
    /* 0x50cb8 */ ldr x8, [x25, #0x28];
    /* 0x50cbc */ ldur x9, [x29, #-0x18];
    /* 0x50cc0 */ cmp x8, x9;
    /* 0x50cc4 */ b.ne #0x50f50;
    /* 0x50cc8 */ add sp, sp, #0x210;
    /* 0x50ccc */ ldp x20, x19, [sp, #0x50];
    /* 0x50cd0 */ ldp x22, x21, [sp, #0x40];
    return x0;
    sub_50134();
    sub_50134();
    sub_50134();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    _ZdlPv();
    sub_8c7c4();
    __stack_chk_fail();
}
