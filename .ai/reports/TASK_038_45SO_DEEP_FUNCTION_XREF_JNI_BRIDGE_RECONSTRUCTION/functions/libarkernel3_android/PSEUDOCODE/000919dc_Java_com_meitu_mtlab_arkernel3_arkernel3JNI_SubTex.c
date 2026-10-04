// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x919dc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getWrap
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x919dc | Size: 28 bytes | SHA256: f4d34bc9e91acc6c62032b4fad222a701fd10fc8275e9fe5e59ed230dafdd510
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction7getWrapEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getWrap(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x919dc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x919e0 */ mov x29, sp;
    /* 0x919e4 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction7getWrapEv();
    /* 0x919ec */ and w0, w0, #1;
    /* 0x919f0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
