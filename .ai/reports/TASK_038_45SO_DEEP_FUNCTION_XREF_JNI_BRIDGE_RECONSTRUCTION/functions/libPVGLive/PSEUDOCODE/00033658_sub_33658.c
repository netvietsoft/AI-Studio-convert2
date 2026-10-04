// Library: libPVGLive.so
// Function ID: libPVGLive::0x33658
// Recovered Name: sub_33658
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x33658 | Size: 344 bytes | SHA256: 0db881ee9c11d8e0f54d32d6a943e1abfa9827acb7b7991a4c02da4157141bdf
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z, __android_log_print, pthread_self
// Strings referenced:
//   "F[%s, L(%d)], T(%p):> MpfTransform: found existing MPF at segment %zu, dataLen=%zu"
//   "prepare"

void sub_33658(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 86 instructions
    /* 0x33658 */ stp x29, x30, [sp, #0x10];
    /* 0x3365c */ stp x26, x25, [sp, #0x20];
    /* 0x33660 */ stp x24, x23, [sp, #0x30];
    /* 0x33664 */ stp x22, x21, [sp, #0x40];
    /* 0x33668 */ stp x20, x19, [sp, #0x50];
    /* 0x3366c */ add x29, sp, #0x10;
    /* 0x33670 */ ldp x10, x8, [x1, #0x18];
    /* 0x33674 */ mov x9, #-1;
    /* 0x33678 */ strb wzr, [x0, #0x18];
    /* 0x3367c */ str x9, [x0, #0x10];
    /* 0x33680 */ subs x8, x8, x10;
    return x0;
    pthread_self();
    __android_log_print();
    _Z15vllog_tag_print13vllog_level_tPKcS1_S1_z();
}
