// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x993c8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1setDirectory
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x993c8 | Size: 148 bytes | SHA256: ed4fe5e3f8f29ad4579faaf7e2732abdb11eeca6310d101f31f8e46fd0b4443a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313GlobalSetting12setDirectoryENS_13DirectoryTypeEPKc

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_GlobalSetting_1setDirectory(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 37 instructions
    /* 0x993c8 */ stp x29, x30, [sp, #-0x30]!;
    /* 0x993cc */ stp x22, x21, [sp, #0x10];
    /* 0x993d0 */ stp x20, x19, [sp, #0x20];
    /* 0x993d4 */ mov x29, sp;
    /* 0x993d8 */ mov w21, w2;
    /* 0x993dc */ cbz x3, #0x99434;
    /* 0x993e0 */ ldr x8, [x0];
    /* 0x993e4 */ mov x1, x3;
    /* 0x993e8 */ mov x2, xzr;
    /* 0x993ec */ mov x19, x3;
    /* 0x993f0 */ mov x20, x0;
    _ZN8mtlabar313GlobalSetting12setDirectoryENS_13DirectoryTypeEPKc();
    return x0;
}
