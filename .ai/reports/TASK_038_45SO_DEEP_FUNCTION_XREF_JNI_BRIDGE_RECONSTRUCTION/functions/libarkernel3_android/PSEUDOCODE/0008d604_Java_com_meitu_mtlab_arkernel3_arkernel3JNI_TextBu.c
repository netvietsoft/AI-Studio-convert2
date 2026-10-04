// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8d604
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1getEditable
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8d604 | Size: 28 bytes | SHA256: 900db94b4a2560a849fa4c03439b66adab9e3e9a39e47118a46ccd4759702f4e
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar323TextBubbleConfiguration11getEditableEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_TextBubbleConfiguration_1getEditable(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8d604 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8d608 */ mov x29, sp;
    /* 0x8d60c */ mov x0, x2;
    _ZNK8mtlabar323TextBubbleConfiguration11getEditableEv();
    /* 0x8d614 */ and w0, w0, #1;
    /* 0x8d618 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
