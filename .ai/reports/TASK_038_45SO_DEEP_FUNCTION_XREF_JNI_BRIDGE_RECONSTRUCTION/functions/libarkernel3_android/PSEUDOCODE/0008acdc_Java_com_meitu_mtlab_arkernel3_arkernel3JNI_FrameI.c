// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8acdc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FrameInfoInterface_1getFrameInfoOption
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8acdc | Size: 32 bytes | SHA256: e9d88d803a5bf4323c7a4c0b51982723e879cc345f45d2af4cc3e73e66654f21
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar318FrameInfoInterface18getFrameInfoOptionE15FrameInfoOption

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_FrameInfoInterface_1getFrameInfoOption(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x8acdc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8ace0 */ mov x29, sp;
    /* 0x8ace4 */ mov w1, w4;
    /* 0x8ace8 */ mov x0, x2;
    _ZNK8mtlabar318FrameInfoInterface18getFrameInfoOptionE15FrameInfoOption();
    /* 0x8acf0 */ and w0, w0, #1;
    /* 0x8acf4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
