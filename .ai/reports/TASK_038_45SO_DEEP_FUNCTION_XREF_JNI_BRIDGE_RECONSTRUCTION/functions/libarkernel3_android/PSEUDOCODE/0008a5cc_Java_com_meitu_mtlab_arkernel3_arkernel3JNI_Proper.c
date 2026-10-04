// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x8a5cc
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Property_1getDisplayName
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x8a5cc | Size: 68 bytes | SHA256: 157829a2190359fdb4c85297e200c0446b15a5b1a95a684e11f0490281e8679b
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZNK8mtlabar38Property14getDisplayNameEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_Property_1getDisplayName(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x8a5cc */ stp x29, x30, [sp, #-0x20]!;
    /* 0x8a5d0 */ str x19, [sp, #0x10];
    /* 0x8a5d4 */ mov x29, sp;
    /* 0x8a5d8 */ mov x19, x0;
    /* 0x8a5dc */ mov x0, x2;
    _ZNK8mtlabar38Property14getDisplayNameEv();
    /* 0x8a5e4 */ cbz x0, #0x8a604;
    /* 0x8a5e8 */ ldr x8, [x19];
    /* 0x8a5ec */ mov x1, x0;
    /* 0x8a5f0 */ ldr x2, [x8, #0x538];
    /* 0x8a5f4 */ mov x0, x19;
    return x0;
}
