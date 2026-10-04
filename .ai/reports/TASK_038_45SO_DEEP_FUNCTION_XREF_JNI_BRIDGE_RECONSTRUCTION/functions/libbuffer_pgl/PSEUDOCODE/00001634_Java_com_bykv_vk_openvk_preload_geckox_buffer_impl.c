// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x1634
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nRead
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1634 | Size: 32 bytes | SHA256: c43bdd8de5b1fd70e7980d22a2a69dcfc98886ed056e6995070a076721a95fce
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nRead(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x1634 */ ldr x8, [x0];
    /* 0x1638 */ mov x1, x4;
    /* 0x163c */ ldr x7, [x8, #0x680];
    /* 0x1640 */ add x8, x2, x3;
    /* 0x1644 */ mov w2, w5;
    /* 0x1648 */ mov w3, w6;
    /* 0x164c */ mov x4, x8;
    /* 0x1650 */ br x7;
}
