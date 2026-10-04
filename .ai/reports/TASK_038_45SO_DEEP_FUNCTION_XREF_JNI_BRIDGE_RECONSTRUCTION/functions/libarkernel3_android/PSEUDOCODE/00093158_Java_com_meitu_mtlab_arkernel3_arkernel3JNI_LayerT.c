// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x93158
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1getMirror
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x93158 | Size: 28 bytes | SHA256: ea4ce3d8dcfaae32b8697550ffb5fd6475e41fa097d956b763399259a5e5bc7c
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar325LayerTransformInteraction9getMirrorEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTransformInteraction_1getMirror(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x93158 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9315c */ mov x29, sp;
    /* 0x93160 */ mov x0, x2;
    _ZN8mtlabar325LayerTransformInteraction9getMirrorEv();
    /* 0x93168 */ and w0, w0, #1;
    /* 0x9316c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
