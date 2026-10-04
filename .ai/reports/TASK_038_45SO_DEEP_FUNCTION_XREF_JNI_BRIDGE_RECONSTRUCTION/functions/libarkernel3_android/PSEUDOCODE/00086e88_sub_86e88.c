// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x86e88
// Recovered Name: sub_86e88
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x86e88 | Size: 40 bytes | SHA256: d73d436921f7111d0e95f4d90994bd50645e1a525487357d47696a07bf99e9c9
// Callers: 1 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar34text53register_com_meitu_mtlab_arkernel3_freetype_GLXBitmapEP7_JNIEnv

void sub_86e88(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 10 instructions
    /* 0x86e88 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x86e8c */ mov x29, sp;
    /* 0x86e90 */ mov x0, x2;
    _ZN8mtlabar34text53register_com_meitu_mtlab_arkernel3_freetype_GLXBitmapEP7_JNIEnv();
    /* 0x86e98 */ mov w8, #6;
    /* 0x86e9c */ cmp w0, #0;
    /* 0x86ea0 */ movk w8, #1, lsl #16;
    /* 0x86ea4 */ csinv w0, w8, wzr, ge;
    /* 0x86ea8 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
