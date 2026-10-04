// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f168
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1getEnable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f168 | Size: 28 bytes | SHA256: 3223aaa29c3e460ad48606dd2ef31b8a65891e92b090e583b50b09ae715c9749
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar326CharSVGBackgroundInterface9getEnableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CharSVGBackgroundInterface_1getEnable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f168 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f16c */ mov x29, sp;
    /* 0x8f170 */ mov x0, x2;
    _ZNK8mtlabar326CharSVGBackgroundInterface9getEnableEv();
    /* 0x8f178 */ and w0, w0, #1;
    /* 0x8f17c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
