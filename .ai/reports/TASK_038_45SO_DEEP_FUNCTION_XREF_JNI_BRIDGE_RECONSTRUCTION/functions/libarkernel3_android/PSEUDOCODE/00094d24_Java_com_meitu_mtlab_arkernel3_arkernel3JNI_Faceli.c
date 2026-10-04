// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94d24
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftControlInstance_1getFaceliftSliderByKeyName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94d24 | Size: 148 bytes | SHA256: 5a14cfd0e0b7e8a77086d06b12502420dff48aecea1b069a41c1dd932f33e195
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323FaceliftControlInstance26getFaceliftSliderByKeyNameEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FaceliftControlInstance_1getFaceliftSliderByKeyName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x94d24 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x94d28 */ stp x22, x21, [sp, #0x10];
    /* 0x94d2c */ stp x20, x19, [sp, #0x20];
    /* 0x94d30 */ mov x29, sp;
    /* 0x94d34 */ mov x21, x2;
    /* 0x94d38 */ cbz x4, #0x94d8c;
    /* 0x94d3c */ ldr x8, [x0];
    /* 0x94d40 */ mov x1, x4;
    /* 0x94d44 */ mov x2, xzr;
    /* 0x94d48 */ mov x19, x4;
    /* 0x94d4c */ mov x20, x0;
    _ZN8mtlabar323FaceliftControlInstance26getFaceliftSliderByKeyNameEPKc();
    _ZN8mtlabar323FaceliftControlInstance26getFaceliftSliderByKeyNameEPKc();
    return x0;
}
