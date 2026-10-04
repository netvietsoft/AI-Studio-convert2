// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8edac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1isEnableTextOnIcon
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8edac | Size: 28 bytes | SHA256: 2cc348db6f196f0d241b0be2c53641953e872a404f189b9f4aaf95d84347b601
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326IconSequenceStyleInterface18isEnableTextOnIconEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_IconSequenceStyleInterface_1isEnableTextOnIcon(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8edac */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8edb0 */ mov x29, sp;
    /* 0x8edb4 */ mov x0, x2;
    _ZNK8mtlabar326IconSequenceStyleInterface18isEnableTextOnIconEv();
    /* 0x8edbc */ and w0, w0, #1;
    /* 0x8edc0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
