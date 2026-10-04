// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8e208
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionAnimationInterface_1getConfigPath
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8e208 | Size: 64 bytes | SHA256: 1a9f7c1eea85a70698b8366dc47f5ddcb5e4bddd68dadd9aed5e84730ea8bc8a
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar327SelectionAnimationInterface13getConfigPathEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_SelectionAnimationInterface_1getConfigPath(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 16 instructions
    /* 0x8e208 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8e20c */ str x19, [sp, #0x10];
    /* 0x8e210 */ mov x29, sp;
    /* 0x8e214 */ mov x19, x0;
    /* 0x8e218 */ mov x0, x2;
    _ZNK8mtlabar327SelectionAnimationInterface13getConfigPathEv();
    /* 0x8e220 */ ldr x8, [x19];
    /* 0x8e224 */ ldrb w9, [x0];
    /* 0x8e228 */ ldr x10, [x0, #0x10];
    /* 0x8e22c */ tst w9, #1;
    /* 0x8e230 */ ldr x2, [x8, #0x538];
}
