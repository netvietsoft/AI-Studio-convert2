// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8b78c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportStickerData_1imageData_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8b78c | Size: 16 bytes | SHA256: 0a3fefe14ee259ac0f80e0e171069312c8187642ab776ae9365194c28da28437
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_ImportStickerData_1imageData_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8b78c */ cbz x2, #0x8b798;
    /* 0x8b790 */ ldr x8, [x4];
    /* 0x8b794 */ str x8, [x2];
    return x0;
}
