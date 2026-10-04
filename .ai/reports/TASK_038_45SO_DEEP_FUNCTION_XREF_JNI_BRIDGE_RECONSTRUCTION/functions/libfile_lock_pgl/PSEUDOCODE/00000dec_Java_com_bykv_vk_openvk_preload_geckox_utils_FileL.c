// Library: libfile_lock_pgl.so
// Function ID: libfile_lock_pgl::0xdec
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nRelease
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0xdec | Size: 116 bytes | SHA256: 496bb5cf9d53bcb3e05e4ae014d29294982acff482a120fffe46453b251d531e
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: __errno, close, strerror
// Strings referenced:
//   "java/lang/RuntimeException"

jobject Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nRelease(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 29 instructions
    /* 0xdec */ stp x29, x30, [sp, #-0x20]!;
    /* 0xdf0 */ stp x20, x19, [sp, #0x10];
    /* 0xdf4 */ mov x29, sp;
    /* 0xdf8 */ mov x19, x0;
    /* 0xdfc */ mov w0, w2;
    close();
    /* 0xe04 */ cmn w0, #1;
    /* 0xe08 */ b.eq #0xe18;
    /* 0xe0c */ ldp x20, x19, [sp, #0x10];
    /* 0xe10 */ ldp x29, x30, [sp], #0x20;
    return x0;
    __errno();
    strerror();
}
