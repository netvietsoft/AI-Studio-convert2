// Library: libfile_lock_pgl.so
// Function ID: libfile_lock_pgl::0xd34
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nGetFD
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0xd34 | Size: 184 bytes | SHA256: 2d05bceaa026b6308a83382172c8a431eeab7d9321cf3e7fbaa4be556f483cd3
// Callers: 0 | Callees: 0 | Imports: 3

// Calls external APIs: __errno, open, strerror
// Strings referenced:
//   "java/lang/RuntimeException"

jobject Java_com_bykv_vk_openvk_preload_geckox_utils_FileLock_nGetFD(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 46 instructions
    /* 0xd34 */ stp x29, x30, [sp, #-0x30]!;
    /* 0xd38 */ stp x22, x21, [sp, #0x10];
    /* 0xd3c */ stp x20, x19, [sp, #0x20];
    /* 0xd40 */ mov x29, sp;
    /* 0xd44 */ ldr x8, [x0];
    /* 0xd48 */ mov x21, x2;
    /* 0xd4c */ mov x1, x2;
    /* 0xd50 */ mov x2, xzr;
    /* 0xd54 */ ldr x8, [x8, #0x548];
    /* 0xd58 */ mov x19, x0;
    /* 0xd5c */ blr x8;
    open();
    __errno();
    strerror();
    return x0;
}
