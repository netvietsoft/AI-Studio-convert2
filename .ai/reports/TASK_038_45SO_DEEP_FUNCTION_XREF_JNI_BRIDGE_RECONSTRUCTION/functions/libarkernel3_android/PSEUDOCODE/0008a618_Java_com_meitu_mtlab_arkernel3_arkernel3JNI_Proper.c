// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a618
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Property_1isHideUI
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a618 | Size: 28 bytes | SHA256: 7951894e119a4c2ca8576d49a2d53f38c70eb92dd2dbd89db4d16d7395f75f0a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar38Property8isHideUIEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Property_1isHideUI(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x8a618 */ stp x29, x30, [sp, #-0x10]!;
    /* 0x8a61c */ mov x29, sp;
    /* 0x8a620 */ mov x0, x2;
    _ZNK8mtlabar38Property8isHideUIEv();
    /* 0x8a628 */ and w0, w0, #1;
    /* 0x8a62c */ ldp x29, x30, [sp], #0x10;
    return x0;
}
