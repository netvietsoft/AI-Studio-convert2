// Library: libarkernel3_android.so
// Function ID: libarkernel3_android::0x98610
// Recovered Name: Java_com_meitu_mtlab_arkernel3_arkernel3JNI_delete_1InterfaceListener
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x98610 | Size: 24 bytes | SHA256: 6c7b6b31556e275d8969e0b5f15964139d49ddda128e289fcae4a94737dbedfa
// Callers: 0 | Callees: 0 | Imports: 0


jobject Java_com_meitu_mtlab_arkernel3_arkernel3JNI_delete_1InterfaceListener(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 6 instructions
    /* 0x98610 */ cbz x2, #0x98624;
    /* 0x98614 */ ldr x8, [x2];
    /* 0x98618 */ mov x0, x2;
    /* 0x9861c */ ldr x1, [x8, #8];
    /* 0x98620 */ br x1;
    return x0;
}
