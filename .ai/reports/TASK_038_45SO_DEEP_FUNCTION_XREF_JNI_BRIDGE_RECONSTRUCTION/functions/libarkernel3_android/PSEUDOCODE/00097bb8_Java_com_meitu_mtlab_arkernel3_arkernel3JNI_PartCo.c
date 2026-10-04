// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97bb8
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1isApply
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97bb8 | Size: 28 bytes | SHA256: b5a3222c96b71f42982247b029f04fde5e355e1288ec1fc020bce8c77926551b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar311PartControl7isApplyEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1isApply(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x97bb8 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x97bbc */ mov x29, sp;
    /* 0x97bc0 */ mov x0, x2;
    _ZNK8mtlabar311PartControl7isApplyEv();
    /* 0x97bc8 */ and w0, w0, #1;
    /* 0x97bcc */ ldp x29, x30, [sp], #0x10;
    return x0;
}
