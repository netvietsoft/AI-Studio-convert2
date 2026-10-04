// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93e38
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireTouchListener
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93e38 | Size: 28 bytes | SHA256: 60ba4befa6cf953acd578af085f67f8fb4d95ae8479c904a6762cc5f0fc01f24
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311DataRequire20requireTouchListenerEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_DataRequire_1requireTouchListener(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93e38 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93e3c */ mov x29, sp;
    /* 0x93e40 */ mov x0, x2;
    _ZNK8mtlabar311DataRequire20requireTouchListenerEv();
    /* 0x93e48 */ and w0, w0, #1;
    /* 0x93e4c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
