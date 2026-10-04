// Library: libfile_lock_pgl.so
// Function ID: libfile_lock_pgl::0xc60
// Recovered Name: sub_c60
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xc60 | Size: 212 bytes | SHA256: 5d2e89cf1be98ea6a89c17c631f9a37b9216cd1f0380074b6ac40799dc89d89d
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: __android_log_print, __errno, __stack_chk_fail, fcntl, strerror
// Strings referenced:
//   "FileLock"
//   "java/lang/RuntimeException"

void sub_c60(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 53 instructions
    /* 0xc60 */ stp x29, x30, [sp, #0x30];
    /* 0xc64 */ str x21, [sp, #0x40];
    /* 0xc68 */ stp x20, x19, [sp, #0x50];
    /* 0xc6c */ add x29, sp, #0x30;
    /* 0xc70 */ mrs x21, tpidr_el0;
    /* 0xc74 */ ldr x9, [x21, #0x28];
    /* 0xc78 */ mov w8, w2;
    /* 0xc7c */ mov x19, x0;
    /* 0xc80 */ sxtw x10, w3;
    /* 0xc84 */ mov w11, #1;
    /* 0xc88 */ mov w12, #-1;
    fcntl();
    __android_log_print();
    __errno();
    strerror();
    return x0;
    __stack_chk_fail();
}
