// Library: libPVGLive.so
// Function ID: libPVGLive::0x6cda0
// Recovered Name: sub_6cda0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x6cda0 | Size: 536 bytes | SHA256: 7712e5a1b23576451616add8878ba3c2b54b12b112f2c106038d3a38ccc94f18
// Callers: 0 | Callees: 3 | Imports: 5

// Calls external APIs: _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z, _ZdlPv, __android_log_print, __stack_chk_fail, pthread_self
// Strings referenced:
//   "F[%s, L(%d)], T(%p):> ExifEditor: failed to scan JPEG segments"
//   "F[%s, L(%d)], T(%p):> ExifEditor: no EXIF segment found in JPEG"
//   "PVGLive"
//   "parseFromJpeg"

void sub_6cda0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 134 instructions
    /* 0x6cda0 */ stp x29, x30, [sp, #0x30];
    /* 0x6cda4 */ str x23, [sp, #0x40];
    /* 0x6cda8 */ stp x22, x21, [sp, #0x50];
    /* 0x6cdac */ stp x20, x19, [sp, #0x60];
    /* 0x6cdb0 */ add x29, sp, #0x30;
    /* 0x6cdb4 */ mrs x23, tpidr_el0;
    /* 0x6cdb8 */ mov w21, wzr;
    /* 0x6cdbc */ ldr x9, [x23, #0x28];
    /* 0x6cdc0 */ stur x9, [x29, #-8];
    /* 0x6cdc4 */ cbz x1, #0x6cf40;
    /* 0x6cdc8 */ mov x8, x2;
    sub_72ec4();
    pthread_self();
    __android_log_print();
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
    _ZdlPv();
    return x0;
    sub_6c014();
    _ZdlPv();
    sub_8c7c4();
    __stack_chk_fail();
}
