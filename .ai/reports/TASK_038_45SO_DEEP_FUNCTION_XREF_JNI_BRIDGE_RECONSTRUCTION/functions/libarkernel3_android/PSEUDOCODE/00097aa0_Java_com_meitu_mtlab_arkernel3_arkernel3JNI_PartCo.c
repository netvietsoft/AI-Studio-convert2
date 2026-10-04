// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x97aa0
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getPartTypeString
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x97aa0 | Size: 68 bytes | SHA256: 5d00f6a2d14ca4917bcacd8509309b0424f7878c781b4bc400f375e7114e87ee
// Callers: 0 | Callees: 0 | Imports: 1

// Calls external APIs: _ZN8mtlabar311PartControl17getPartTypeStringEv

jlong Java_com_meitu_mtlab_arkernel3_arkernel3JNI_PartControl_1getPartTypeString(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 17 instructions
    /* 0x97aa0 */ stp x29, x30, [sp, #-0x20]!;
    /* 0x97aa4 */ str x19, [sp, #0x10];
    /* 0x97aa8 */ mov x29, sp;
    /* 0x97aac */ mov x19, x0;
    /* 0x97ab0 */ mov x0, x2;
    _ZN8mtlabar311PartControl17getPartTypeStringEv();
    /* 0x97ab8 */ cbz x0, #0x97ad8;
    /* 0x97abc */ ldr x8, [x19];
    /* 0x97ac0 */ mov x1, x0;
    /* 0x97ac4 */ ldr x2, [x8, #0x538];
    /* 0x97ac8 */ mov x0, x19;
    return x0;
}
