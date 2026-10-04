// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x92198
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableTextMirror
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x92198 | Size: 28 bytes | SHA256: c4e42fb1355a00deabd7f54e196b74fb464eb00dba9aa84335fe270de3a53c90
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar320LayerTextInteraction19getEnableTextMirrorEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_LayerTextInteraction_1getEnableTextMirror(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x92198 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x9219c */ mov x29, sp;
    /* 0x921a0 */ mov x0, x2;
    _ZN8mtlabar320LayerTextInteraction19getEnableTextMirrorEv();
    /* 0x921a8 */ and w0, w0, #1;
    /* 0x921ac */ ldp x29, x30, [sp], #0x10;
    return x0;
}
