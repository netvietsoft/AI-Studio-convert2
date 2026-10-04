// Library: libPVGLive.so
// Function ID: libPVGLive::0x505d4
// Recovered Name: sub_505d4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x505d4 | Size: 1724 bytes | SHA256: 7ea7b3df4f1967687905e13ff4d83d94ec20f47e96cfce09e09c2633fedc74c7
// Callers: 1 | Callees: 8 | Imports: 4

// Calls external APIs: _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z, _ZdlPv, __android_log_print, pthread_self
// Strings referenced:
//   "F[%s, L(%d)], T(%p):> Decoder extractVideo: applied video orientation patch (track=%u, targetOrientation=%d, matrix=%d, timedValue=%d, preRotatedPixels=%d, segments=%zu)"
//   "F[%s, L(%d)], T(%p):> Decoder video orientation patch preparation failed: %s"
//   "F[%s, L(%d)], T(%p):> Decoder video rotation parse failed: %s"
//   "PVGLive"
//   "none"

void sub_505d4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 431 instructions
    /* 0x505d4 */ stp x29, x30, [sp, #-0x60]!;
    /* 0x505d8 */ stp x28, x27, [sp, #0x10];
    /* 0x505dc */ stp x26, x25, [sp, #0x20];
    /* 0x505e0 */ stp x24, x23, [sp, #0x30];
    /* 0x505e4 */ stp x22, x21, [sp, #0x40];
    /* 0x505e8 */ stp x20, x19, [sp, #0x50];
    /* 0x505ec */ mov x29, sp;
    /* 0x505f0 */ sub sp, sp, #0x210;
    /* 0x505f4 */ mrs x25, tpidr_el0;
    /* 0x505f8 */ ldr x8, [x25, #0x28];
    /* 0x505fc */ stur x8, [x29, #-0x18];
    sub_28b38();
    sub_2dca8();
    sub_28b74();
    sub_78b9c();
    sub_88334();
    sub_78e28();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    pthread_self();
    sub_78e5c();
    __android_log_print();
    sub_78e5c();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    _ZdlPv();
    sub_88558();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
}
