// Library: libfile_lock_pgl.so
// Function ID: libfile_lock_pgl::0xb20
// Recovered Name: sub_b20
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0xb20 | Size: 208 bytes | SHA256: de18641db2bb898cd822ebbce47734ac66c1ae368c62c74d3f79f4babc0d130e
// Callers: 0 | Callees: 0 | Imports: 5

// Calls external APIs: __android_log_print, __errno, __stack_chk_fail, fcntl, strerror
// Strings referenced:
//   "FileLock"
//   "java/lang/RuntimeException"

void sub_b20(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 52 instructions
    /* 0xb20 */ stp x29, x30, [sp, #0x30];
    /* 0xb24 */ str x21, [sp, #0x40];
    /* 0xb28 */ stp x20, x19, [sp, #0x50];
    /* 0xb2c */ add x29, sp, #0x30;
    /* 0xb30 */ mrs x21, tpidr_el0;
    /* 0xb34 */ ldr x9, [x21, #0x28];
    /* 0xb38 */ mov w8, w2;
    /* 0xb3c */ mov x19, x0;
    /* 0xb40 */ mov w10, #2;
    /* 0xb44 */ mov w11, #-1;
    /* 0xb48 */ add x2, sp, #8;
    fcntl();
    __android_log_print();
    __errno();
    strerror();
    return x0;
    __stack_chk_fail();
}
