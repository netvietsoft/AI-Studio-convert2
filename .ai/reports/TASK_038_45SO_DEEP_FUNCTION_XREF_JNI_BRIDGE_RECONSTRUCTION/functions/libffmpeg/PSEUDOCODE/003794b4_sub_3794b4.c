// Library: libffmpeg.so
// Function ID: libffmpeg::0x3794b4
// Recovered Name: sub_3794b4
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3794b4 | Size: 1208 bytes | SHA256: f3cc958b24db1d17d02ac1af0dff8b13e03105292bd3bb73bf978c71d00c8a53
// Callers: 0 | Callees: 21 | Imports: 1

// Calls external APIs: ff_cbs_read_simple_unsigned
// Strings referenced:
//   "aspect_ratio_idc"
//   "aspect_ratio_info_present_flag"
//   "cb_qp_offset_list[i]"
//   "chroma_qp_offset_list_enabled_flag"
//   "chroma_qp_offset_list_len_minus1"

void sub_3794b4(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 302 instructions
    /* 0x3794b4 */ adrp x3, #0xcd000;
    /* 0x3794b8 */ add x3, x3, #0x3ac;
    /* 0x3794bc */ add x1, sp, #0x28;
    /* 0x3794c0 */ add x4, sp, #0xd0;
    sub_39dea8();
    /* 0x3794c8 */ tbnz w0, #0x1f, #0x37ab74;
    /* 0x3794cc */ ldrb w8, [sp, #0xd0];
    /* 0x3794d0 */ strb w8, [x22, #0x77];
    /* 0x3794d4 */ cbz w8, #0x3794ec;
    /* 0x3794d8 */ add x1, sp, #0x28;
    /* 0x3794dc */ add x2, x22, #0x78;
    sub_38b320();
    sub_39dea8();
    sub_39e490();
    sub_39e140();
    sub_38899c();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39dea8();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39fe70();
    ff_cbs_read_simple_unsigned();
    sub_39e318();
    sub_39dea8();
    sub_39df40();
    ff_cbs_read_simple_unsigned();
    sub_39e02c();
    sub_3a06b4();
    sub_38899c();
    sub_3a0a70();
    sub_39e2e4();
    sub_388b28();
    sub_3a0a70();
    sub_39e2e4();
    sub_388b28();
    sub_39fe3c();
    sub_38899c();
    sub_39fe3c();
    sub_38899c();
    sub_39dea8();
    sub_39e6c0();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39e6c0();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39ee94();
    sub_39dea8();
    sub_39ee94();
    sub_39e79c();
    sub_39ee94();
    sub_3a0878();
    sub_39e6c0();
    ff_cbs_read_simple_unsigned();
    sub_39e6c0();
    sub_39f48c();
    sub_3a06a0();
    sub_388b28();
}
