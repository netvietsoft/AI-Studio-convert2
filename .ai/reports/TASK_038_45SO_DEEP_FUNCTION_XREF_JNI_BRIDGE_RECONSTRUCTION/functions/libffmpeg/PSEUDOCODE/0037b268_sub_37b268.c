// Library: libffmpeg.so
// Function ID: libffmpeg::0x37b268
// Recovered Name: sub_37b268
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37b268 | Size: 1420 bytes | SHA256: d950b6a6266304270783aa516e49fe09c709297124d8baf082c3a414bc18b219
// Callers: 0 | Callees: 32 | Imports: 1

// Calls external APIs: ff_cbs_write_unsigned
// Strings referenced:
//   "alignment_bit_equal_to_one"
//   "alignment_bit_equal_to_zero"
//   "chroma_format_idc"
//   "entry_point_offset_minus1[i]"
//   "log2_diff_max_min_luma_coding_block_size"

void sub_37b268(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 355 instructions
    /* 0x37b268 */ ldrb w8, [x23, #0x85b];
    /* 0x37b26c */ ldrb w4, [x21, #0x129];
    /* 0x37b270 */ cbz w8, #0x37b574;
    /* 0x37b274 */ adrp x3, #0xd2000;
    /* 0x37b278 */ add x3, x3, #0x74d;
    sub_39de58();
    /* 0x37b280 */ tbnz w0, #0x1f, #0x37e80c;
    /* 0x37b284 */ ldrb w8, [x23, #0x1b1];
    /* 0x37b288 */ cbnz w8, #0x37b588;
    /* 0x37b28c */ ldrb w8, [x23, #0x1b0];
    /* 0x37b290 */ cbz w8, #0x37b588;
    sub_39de58();
    sub_39e3d8();
    sub_3a2028();
    sub_39ee58();
    sub_39f37c();
    sub_3a02b4();
    sub_39de58();
    sub_3a21a4();
    sub_39fcf8();
    sub_39de58();
    sub_39df4c();
    sub_39f37c();
    sub_39df6c();
    sub_39e6a8();
    sub_39dfd4();
    sub_3a1b4c();
    sub_3a1ecc();
    sub_39ee70();
    sub_39eea0();
    sub_39e5a0();
    ff_cbs_write_unsigned();
    sub_39f10c();
    sub_39e6cc();
    sub_39f30c();
    sub_39df58();
    sub_39debc();
    sub_39debc();
    sub_39e514();
    sub_39de58();
    sub_39e08c();
    sub_39eed0();
    sub_39e0dc();
    sub_39e0dc();
    sub_39e80c();
    sub_39df4c();
    sub_39df80();
    sub_39e80c();
    sub_39e80c();
    sub_39de58();
    sub_39de58();
    sub_39f17c();
    sub_39e0dc();
    sub_39de58();
    sub_39e3d8();
    sub_3a1e50();
    sub_39de58();
    sub_39e4fc();
    sub_39e4fc();
    sub_39e3d8();
    sub_39e3d8();
    sub_39e1f8();
    sub_3a02b4();
}
