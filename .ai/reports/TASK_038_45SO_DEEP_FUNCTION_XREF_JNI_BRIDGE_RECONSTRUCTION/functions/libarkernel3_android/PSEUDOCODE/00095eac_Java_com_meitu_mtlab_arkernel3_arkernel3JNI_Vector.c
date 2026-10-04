// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x95eac
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorBrushCache_1add
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x95eac | Size: 220 bytes | SHA256: d00407035757aa73462bbf777f0c7267dd46510bb4ae6c6e0819c75571d3f733
// Callers: 0 | Callees: 2 | Imports: 1

// Calls external APIs: _ZdlPv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_VectorBrushCache_1add(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 55 instructions
    /* 0x95eac */ stp x29, x30, [sp, #-0x30]!;
    /* 0x95eb0 */ str x21, [sp, #0x10];
    /* 0x95eb4 */ stp x20, x19, [sp, #0x20];
    /* 0x95eb8 */ mov x29, sp;
    /* 0x95ebc */ mov x0, x2;
    /* 0x95ec0 */ mov x19, x2;
    /* 0x95ec4 */ mov x20, x4;
    /* 0x95ec8 */ ldr x8, [x0, #0x10]!;
    /* 0x95ecc */ ldur x21, [x0, #-8];
    /* 0x95ed0 */ cmp x21, x8;
    /* 0x95ed4 */ b.hs #0x95ee0;
    sub_9c260();
    _ZdlPv();
    return x0;
    sub_9c24c();
}
