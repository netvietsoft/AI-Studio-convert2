// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9103c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorLineLayoutConfigInterface_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9103c | Size: 220 bytes | SHA256: 5de58cf9f7f0675fd1093c735d3543f6fa57684d43a1653289c9c7af1722cf27
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorLineLayoutConfigInterface_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x9103c */ stp x29, x30, [sp, #-0x30]!;
    /* 0x91040 */ str x21, [sp, #0x10];
    /* 0x91044 */ stp x20, x19, [sp, #0x20];
    /* 0x91048 */ mov x29, sp;
    /* 0x9104c */ mov x0, x2;
    /* 0x91050 */ mov x19, x2;
    /* 0x91054 */ mov x20, x4;
    /* 0x91058 */ ldr x8, [x0, #0x10]!;
    /* 0x9105c */ ldur x21, [x0, #-8];
    /* 0x91060 */ cmp x21, x8;
    /* 0x91064 */ b.hs #0x91070;
    sub_9bd90();
    _ZdlPv();
    return x0;
    sub_9bd7c();
}
