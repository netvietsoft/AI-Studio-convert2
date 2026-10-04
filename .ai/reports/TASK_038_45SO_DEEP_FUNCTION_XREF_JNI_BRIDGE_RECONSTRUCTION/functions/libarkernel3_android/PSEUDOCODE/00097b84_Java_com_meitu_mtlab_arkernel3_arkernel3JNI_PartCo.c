// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97b84
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getPartControlVisible
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97b84 | Size: 28 bytes | SHA256: 8793954882b70c898076f86a30630db8e966c26eec093fd95ce4aa6d0a015344
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl21getPartControlVisibleEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getPartControlVisible(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x97b84 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x97b88 */ mov x29, sp;
    /* 0x97b8c */ mov x0, x2;
    _ZN8mtlabar311PartControl21getPartControlVisibleEv();
    /* 0x97b94 */ and w0, w0, #1;
    /* 0x97b98 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
