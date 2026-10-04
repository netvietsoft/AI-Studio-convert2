// Library: libPVGVideoCodec.so
// Function ID: libPVGVideoCodec::0x73340
// Recovered Name: JNI_OnLoad
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x73340 | Size: 192 bytes | SHA256: 0fe6af2e9ee61fd1ad2421fdcdffba599da87fe8a32a2061261f6f488943d4b8
// Callers: 0 | Callees: 1 | Imports: 2

// Calls external APIs: _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z, pthread_self
// Strings referenced:
//   "F[%s, L(%d)], T(%p):> JNI_OnLoad"
//   "F[%s, L(%d)], T(%p):> aicodec_set_jvm failed"
//   "JNI_OnLoad"

jobject JNI_OnLoad(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 48 instructions
    /* 0x73340 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x73344 */ stp x20, x19, [sp, #0x10];
    /* 0x73348 */ mov x29, sp;
    /* 0x7334c */ adrp x19, #0x11a000;
    /* 0x73350 */ ldr x19, [x19, #0xd58];
    /* 0x73354 */ ldr w8, [x19];
    /* 0x73358 */ cmp w8, #3;
    /* 0x7335c */ b.gt #0x73398;
    /* 0x73360 */ mov x20, x0;
    pthread_self();
    /* 0x73368 */ nop ;
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    sub_97fb0();
    return x0;
    pthread_self();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    return x0;
}
