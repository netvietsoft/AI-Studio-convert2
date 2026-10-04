// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92d08
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1isEndTimestampDisabled
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92d08 | Size: 28 bytes | SHA256: aae335aea3d67531129a9ec8723593c9d3b37436000230353976af3172363125
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerAnimationInteraction22isEndTimestampDisabledEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerAnimationInteraction_1isEndTimestampDisabled(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92d08 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x92d0c */ mov x29, sp;
    /* 0x92d10 */ mov x0, x2;
    _ZN8mtlabar325LayerAnimationInteraction22isEndTimestampDisabledEv();
    /* 0x92d18 */ and w0, w0, #1;
    /* 0x92d1c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
