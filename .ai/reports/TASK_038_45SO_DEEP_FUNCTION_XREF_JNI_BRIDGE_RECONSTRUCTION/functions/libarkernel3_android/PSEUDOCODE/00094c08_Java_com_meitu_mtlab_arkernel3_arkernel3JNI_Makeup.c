// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x94c08
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MakeupControl_1getIsStaticOpacityControl
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x94c08 | Size: 28 bytes | SHA256: fd5e47e08e9d5302ba00056a5bc575d83c378c30d4a1e0e2a9ba73aeb74395d9
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar313MakeupControl25getIsStaticOpacityControlEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_MakeupControl_1getIsStaticOpacityControl(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x94c08 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x94c0c */ mov x29, sp;
    /* 0x94c10 */ mov x0, x2;
    _ZN8mtlabar313MakeupControl25getIsStaticOpacityControlEv();
    /* 0x94c18 */ and w0, w0, #1;
    /* 0x94c1c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
