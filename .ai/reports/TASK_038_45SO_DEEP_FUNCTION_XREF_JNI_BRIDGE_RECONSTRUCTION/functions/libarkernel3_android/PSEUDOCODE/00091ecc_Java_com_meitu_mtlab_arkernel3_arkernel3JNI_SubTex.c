// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x91ecc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getContainBgOrFg
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x91ecc | Size: 28 bytes | SHA256: bfcea61b62231aded26b020dc9c285ae6ea572ea75f0dafc1117a0f175befe65
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar323SubTextLayerInteraction16getContainBgOrFgEv

jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SubTextLayerInteraction_1getContainBgOrFg(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 7 instructions
    /* 0x91ecc */ stp x29, x30, [sp, #-0x10]!;
    /* 0x91ed0 */ mov x29, sp;
    /* 0x91ed4 */ mov x0, x2;
    _ZN8mtlabar323SubTextLayerInteraction16getContainBgOrFgEv();
    /* 0x91edc */ and w0, w0, #1;
    /* 0x91ee0 */ ldp x29, x30, [sp], #0x10;
    return x0;
}
