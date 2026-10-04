// Library: libbuffer_pgl.so
// Function ID: libbuffer_pgl::0x1614
// Recovered Name: Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nWrite
// Visibility: JNI_DIRECT_EXPORT | Confidence: FACT
// Address: 0x1614 | Size: 32 bytes | SHA256: dc12ca652aad9785ccacea5f237c93a2920c5709a574ddad06b95b59bd9ea1ff
// Callers: 0 | Callees: 0 | Imports: 0


jlong Java_com_bykv_vk_openvk_preload_geckox_buffer_impl_MemoryBuffer_nWrite(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 8 instructions
    /* 0x1614 */ ldr x8, [x0];
    /* 0x1618 */ mov x1, x4;
    /* 0x161c */ ldr x7, [x8, #0x640];
    /* 0x1620 */ add x8, x2, x3;
    /* 0x1624 */ mov w2, w5;
    /* 0x1628 */ mov w3, w6;
    /* 0x162c */ mov x4, x8;
    /* 0x1630 */ br x7;
}
