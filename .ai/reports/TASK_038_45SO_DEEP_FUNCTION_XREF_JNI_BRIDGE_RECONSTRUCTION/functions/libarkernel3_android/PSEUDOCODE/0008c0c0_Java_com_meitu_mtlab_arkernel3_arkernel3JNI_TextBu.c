// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8c0c0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1scaleSize_1set
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8c0c0 | Size: 16 bytes | SHA256: c775e54b166943a33ac670f7eaf102eb6094fdeca9897d866fb5acdc05e879fb
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleBoxConfig_1scaleSize_1set(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 4 instructions
    /* 0x8c0c0 */ cbz x2, #0x8c0cc;
    /* 0x8c0c4 */ ldr q0, [x4];
    /* 0x8c0c8 */ stur q0, [x2, #0x14];
    return x0;
}
