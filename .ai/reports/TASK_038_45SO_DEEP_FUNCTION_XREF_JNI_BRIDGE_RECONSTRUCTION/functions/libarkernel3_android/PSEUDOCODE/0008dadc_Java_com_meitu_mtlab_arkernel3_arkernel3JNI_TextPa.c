// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8dadc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getEnableAspectRatio
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8dadc | Size: 28 bytes | SHA256: 1fd5585210cc3e70209bb64693393218af4d4db112ffdee0ccb27f34a8afb58f
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar321TextPathConfiguration20getEnableAspectRatioEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextPathConfiguration_1getEnableAspectRatio(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8dadc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8dae0 */ mov x29, sp;
    /* 0x8dae4 */ mov x0, x2;
    _ZNK8mtlabar321TextPathConfiguration20getEnableAspectRatioEv();
    /* 0x8daec */ and w0, w0, #1;
    /* 0x8daf0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
