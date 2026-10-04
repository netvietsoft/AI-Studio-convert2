// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8f708
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1getEnablePosition
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8f708 | Size: 28 bytes | SHA256: c4440417f8b7d6839f5919abef1a6bfafba8cae8f0bfce6070608cbfde049a75
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar324CustomTransformInterface17getEnablePositionEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_CustomTransformInterface_1getEnablePosition(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8f708 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8f70c */ mov x29, sp;
    /* 0x8f710 */ mov x0, x2;
    _ZNK8mtlabar324CustomTransformInterface17getEnablePositionEv();
    /* 0x8f718 */ and w0, w0, #1;
    /* 0x8f71c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
