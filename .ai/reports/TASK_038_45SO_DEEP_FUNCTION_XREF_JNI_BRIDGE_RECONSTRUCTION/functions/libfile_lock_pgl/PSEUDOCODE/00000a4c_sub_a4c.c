// Library: libfile_lock_pgl.so
// Function ID: libfile_lock_pgl::0xa4c
// Recovered Name: sub_a4c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xa4c | Size: 208 bytes | SHA256: e0beb55e25b42101b724f4eaebb470e81752a259576d96687ab8e2acc8fc70e9
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: __android_log_print, __errno, __stack_chk_fail, fcntl, strerror
// Strings referenced:
//   "FileLock"
//   "java/lang/RuntimeException"

void sub_a4c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0xa4c */ stp x29, x30, [sp, #0x30];
    /* 0xa50 */ str x21, [sp, #0x40];
    /* 0xa54 */ stp x20, x19, [sp, #0x50];
    /* 0xa58 */ add x29, sp, #0x30;
    /* 0xa5c */ mrs x21, tpidr_el0;
    /* 0xa60 */ ldr x9, [x21, #0x28];
    /* 0xa64 */ mov w8, w2;
    /* 0xa68 */ mov x19, x0;
    /* 0xa6c */ mov w10, #1;
    /* 0xa70 */ mov w11, #-1;
    /* 0xa74 */ add x2, sp, #8;
    fcntl();
    __android_log_print();
    __errno();
    strerror();
    return x0;
    __stack_chk_fail();
}
