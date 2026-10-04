// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98990
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1acquireTexture2D
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98990 | Size: 196 bytes | SHA256: 7adb75704c1e0688086c1c3b0fd333b0e9ba4a1bc63d4b72851c099993803036
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VisualAllocator_1acquireTexture2D(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x98990 */ stp x29, x30, [sp, #-0x50]!;
    /* 0x98994 */ str x25, [sp, #0x10];
    /* 0x98998 */ stp x24, x23, [sp, #0x20];
    /* 0x9899c */ stp x22, x21, [sp, #0x30];
    /* 0x989a0 */ stp x20, x19, [sp, #0x40];
    /* 0x989a4 */ mov x29, sp;
    /* 0x989a8 */ mov x21, x7;
    /* 0x989ac */ mov x22, x6;
    /* 0x989b0 */ mov x23, x5;
    /* 0x989b4 */ mov x19, x4;
    /* 0x989b8 */ mov x25, x2;
    return x0;
}
