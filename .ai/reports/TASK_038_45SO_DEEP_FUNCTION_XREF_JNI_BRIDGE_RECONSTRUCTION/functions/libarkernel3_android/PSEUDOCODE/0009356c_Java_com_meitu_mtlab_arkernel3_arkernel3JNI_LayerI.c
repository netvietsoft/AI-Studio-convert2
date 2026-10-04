// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x9356c
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getIsCurrentRenderThumbnail
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x9356c | Size: 28 bytes | SHA256: 98ea62f0d4fe52b97d6afa47c6b1f606cd3f9e16438dc91ec84b903a8df1c311
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar316LayerInteraction27getIsCurrentRenderThumbnailEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerInteraction_1getIsCurrentRenderThumbnail(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x9356c */ stp x29, x30, [sp, #-0x10]!;
    /* 0x93570 */ mov x29, sp;
    /* 0x93574 */ mov x0, x2;
    _ZN8mtlabar316LayerInteraction27getIsCurrentRenderThumbnailEv();
    /* 0x9357c */ and w0, w0, #1;
    /* 0x93580 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
