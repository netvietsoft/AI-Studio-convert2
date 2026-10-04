// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91984
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getHorizontal
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91984 | Size: 28 bytes | SHA256: c6a111cdcdcb5416879f7f0fa2acc1aca9202b6176b16a680102c5df4f960753
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction13getHorizontalEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getHorizontal(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91984 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91988 */ mov x29, sp;
    /* 0x9198c */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction13getHorizontalEv();
    /* 0x91994 */ and w0, w0, #1;
    /* 0x91998 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
