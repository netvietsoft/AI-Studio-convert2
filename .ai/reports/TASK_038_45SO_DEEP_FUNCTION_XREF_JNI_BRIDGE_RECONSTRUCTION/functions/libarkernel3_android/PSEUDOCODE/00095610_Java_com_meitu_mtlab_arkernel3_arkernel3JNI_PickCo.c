// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95610
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PickColorControl_1getCurrentValue
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95610 | Size: 44 bytes | SHA256: f134ed50a2fe79d3900f60138d60e293df4f95a99cbc11b383941eee7baa05c3
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar316PickColorControl15getCurrentValueEmPfS1_S1_

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PickColorControl_1getCurrentValue(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 11 instructions
    /* 0x95610 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x95614 */ mov x29, sp;
    /* 0x95618 */ mov x3, x6;
    /* 0x9561c */ mov x1, x4;
    /* 0x95620 */ mov x0, x2;
    /* 0x95624 */ mov x2, x5;
    /* 0x95628 */ mov x4, x7;
    _ZNK8mtlabar316PickColorControl15getCurrentValueEmPfS1_S1_();
    /* 0x95630 */ and w0, w0, #1;
    /* 0x95634 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
