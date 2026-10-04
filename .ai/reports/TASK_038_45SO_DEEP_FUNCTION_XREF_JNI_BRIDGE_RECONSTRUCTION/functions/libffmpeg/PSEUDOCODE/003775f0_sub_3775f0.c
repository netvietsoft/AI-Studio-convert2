// Library: libffmpeg.so
// Function ID: libffmpeg::0x3775f0
// Recovered Name: sub_3775f0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3775f0 | Size: 736 bytes | SHA256: a7c97da6185710d594377523b7066baac3f4bbfd69d391ad494cfe36478ef132
// Callers: 0 | Callees: 16 | Imports: 3

// Calls external APIs: av_log, ff_cbs_read_simple_unsigned, ff_cbs_read_unsigned
// Strings referenced:
//   "entry_point_offset_minus1[i]"
//   "num_entry_point_offsets"
//   "offset_len_minus1"
//   "short_term_ref_pic_set_idx"
//   "short_term_ref_pic_set_sps_flag"

void sub_3775f0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 184 instructions
    /* 0x3775f0 */ ldrb w9, [x29, #0x17];
    /* 0x3775f4 */ ldrb w8, [x29, #0x18];
    /* 0x3775f8 */ cbz w9, #0x377754;
    /* 0x3775fc */ ldrb w9, [x29, #0x19];
    /* 0x377600 */ add w9, w9, #1;
    /* 0x377604 */ cbz w8, #0x377760;
    /* 0x377608 */ mul w8, w9, w28;
    /* 0x37760c */ sub w6, w8, #1;
    /* 0x377610 */ b #0x377768;
    /* 0x377614 */ ldr x0, [x19];
    /* 0x377618 */ and x3, x8, #0xff;
    sub_3a1f2c();
    sub_39ee58();
    sub_39e6a8();
    sub_39eee8();
    ff_cbs_read_unsigned();
    sub_39dea8();
    sub_39e490();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39f908();
    sub_39faf0();
    sub_39e02c();
    av_log();
    sub_39dff8();
    sub_38899c();
    sub_3a1b4c();
    sub_39f908();
    sub_3a0ba4();
    sub_39dff8();
    sub_3a1450();
    sub_39e5a0();
    ff_cbs_read_unsigned();
}
