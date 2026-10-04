// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9a1bc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1getOption
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9a1bc | Size: 32 bytes | SHA256: bb5ba4bff2bff5f7297d2a553f4d0a3a8bf83192d07544403f380bce14b233eb
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar39Interface9getOptionENS_10OptionTypeE

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Interface_1getOption(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x9a1bc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9a1c0 */ mov x29, sp;
    /* 0x9a1c4 */ mov w1, w4;
    /* 0x9a1c8 */ mov x0, x2;
    _ZN8mtlabar39Interface9getOptionENS_10OptionTypeE();
    /* 0x9a1d0 */ and w0, w0, #1;
    /* 0x9a1d4 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
