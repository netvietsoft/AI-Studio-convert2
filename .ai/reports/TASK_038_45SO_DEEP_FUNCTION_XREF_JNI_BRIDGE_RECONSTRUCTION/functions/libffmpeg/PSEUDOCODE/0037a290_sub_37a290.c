// Library: libffmpeg.so
// Function ID: libffmpeg::0x37a290
// Recovered Name: sub_37a290
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37a290 | Size: 2280 bytes | SHA256: b06482aff4bf31716fed5861adc4a149f2445ac0f6fac3ab1d2188e4f0329453
// Callers: 0 | Callees: 41 | Imports: 2

// Calls external APIs: ff_cbs_read_simple_unsigned, ff_cbs_read_unsigned
// Strings referenced:
//   "bitstream_restriction_flag"
//   "chroma_bit_depth_cm_input_minus8"
//   "chroma_bit_depth_cm_output_minus8"
//   "chroma_bit_depth_entry_minus8"
//   "chroma_loc_info_present_flag"

void sub_37a290(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 570 instructions
    /* 0x37a290 */ adrp x3, #0xd7000;
    /* 0x37a294 */ add x3, x3, #0x613;
    /* 0x37a298 */ add x1, sp, #0x28;
    /* 0x37a29c */ add x4, sp, #0xd0;
    sub_39dea8();
    /* 0x37a2a4 */ tbnz w0, #0x1f, #0x37ab74;
    sub_39ee94();
    /* 0x37a2ac */ strb w8, [x9, #0x77];
    /* 0x37a2b0 */ cbz w8, #0x37a310;
    /* 0x37a2b4 */ adrp x2, #0xa7000;
    /* 0x37a2b8 */ add x2, x2, #0x47e;
    sub_39eae8();
    sub_39e6c0();
    sub_3a06b4();
    sub_38899c();
    sub_39e6c0();
    sub_39dea8();
    sub_39e6c0();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39e6c0();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39e6c0();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39ee94();
    sub_39e8a0();
    sub_38899c();
    sub_39e6c0();
    sub_39e8a0();
    sub_38899c();
    sub_39e6c0();
    sub_39e8a0();
    sub_38899c();
    sub_39e6c0();
    sub_39e8a0();
    sub_38899c();
    sub_39e6c0();
    sub_39dea8();
    sub_39ee94();
    sub_39eb24();
    sub_39f394();
    ff_cbs_read_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39ee94();
    sub_39dff8();
    sub_38899c();
    sub_39dea8();
    sub_39ee94();
    sub_38ad50();
    sub_39dea8();
    sub_39dea8();
    sub_39e484();
    sub_3a1e84();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39e484();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39e484();
    sub_39dff8();
    sub_38899c();
    sub_39e484();
    sub_39e29c();
    sub_38899c();
    sub_39e484();
    sub_39e29c();
    sub_38899c();
    sub_39e484();
    sub_39e29c();
    sub_38899c();
    sub_39e484();
    sub_39e29c();
    sub_38899c();
    sub_39e484();
    sub_39dea8();
    sub_39e0fc();
    sub_38899c();
    sub_3a185c();
    sub_3a0afc();
    ff_cbs_read_unsigned();
    sub_3a0ea8();
    sub_39e454();
    sub_3a1528();
    sub_39df40();
    ff_cbs_read_simple_unsigned();
    sub_3a1528();
    sub_3a0eb8();
    sub_38b0d8();
    sub_3a07d4();
    sub_39df4c();
    sub_38a038();
    sub_39eab8();
    sub_3a0158();
    ff_cbs_read_unsigned();
    sub_39e884();
    sub_38899c();
    sub_39e884();
    sub_38899c();
    sub_39e884();
    sub_38899c();
    sub_39e884();
    sub_38899c();
    sub_3a1834();
    ff_cbs_read_simple_unsigned();
    sub_3a1834();
    ff_cbs_read_simple_unsigned();
    sub_3a07b8();
    sub_388b28();
    sub_3a07b8();
    sub_388b28();
    sub_3a0eb8();
    sub_3a1c68();
    sub_38bac8();
    sub_39dea8();
    sub_39df40();
    ff_cbs_read_simple_unsigned();
    sub_39dea8();
    sub_3a079c();
    sub_388b28();
    sub_3a079c();
    sub_388b28();
    sub_39f170();
    sub_388b28();
    sub_39dea8();
    sub_3a0b24();
    sub_38899c();
    sub_39dea8();
    sub_39e97c();
    sub_38899c();
    sub_39f008();
    sub_3a185c();
    ff_cbs_read_unsigned();
    sub_38b0d8();
    sub_3a07d4();
    sub_39df4c();
    sub_38a09c();
}
