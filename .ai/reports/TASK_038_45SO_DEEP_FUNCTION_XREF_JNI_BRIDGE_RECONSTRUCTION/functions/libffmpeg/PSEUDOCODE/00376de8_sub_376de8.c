// Library: libffmpeg.so
// Function ID: libffmpeg::0x376de8
// Recovered Name: sub_376de8
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x376de8 | Size: 1184 bytes | SHA256: ffb1cdf7cd84e8885beb9b994971d09d601a4956cc4c02c4e09855768751b5bf
// Callers: 0 | Callees: 24 | Imports: 3

// Calls external APIs: ff_cbs_read_simple_unsigned, ff_cbs_read_unsigned, ff_cbs_trace_header
// Strings referenced:
//   "Access Unit Delimiter"
//   "Picture Parameter Set"
//   "Slice Segment Header"
//   "cabac_init_present_flag"
//   "constrained_intra_pred_flag"

void sub_376de8(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 296 instructions
    /* 0x376de8 */ stp x29, x30, [sp, #0x100];
    /* 0x376dec */ stp x28, x27, [sp, #0x110];
    /* 0x376df0 */ stp x26, x25, [sp, #0x120];
    /* 0x376df4 */ stp x24, x23, [sp, #0x130];
    /* 0x376df8 */ stp x22, x21, [sp, #0x140];
    /* 0x376dfc */ stp x20, x19, [sp, #0x150];
    sub_3a1e70();
    /* 0x376e04 */ mov w21, #0xb1b7;
    /* 0x376e08 */ str wzr, [sp, #0x38];
    /* 0x376e0c */ lsl w9, w9, #3;
    /* 0x376e10 */ movk w21, #0xbebb, lsl #16;
    sub_3a0e50();
    sub_39e0b4();
    sub_3a0eb8();
    sub_38a0f0();
    sub_39dea8();
    sub_39dea8();
    sub_39f93c();
    sub_39def0();
    ff_cbs_read_unsigned();
    sub_3a221c();
    ff_cbs_trace_header();
    sub_38a0f0();
    sub_3a0ac8();
    sub_39fa50();
    sub_39e0b4();
    sub_3a0c7c();
    sub_38a0f0();
    sub_39f93c();
    sub_3a0170();
    sub_38899c();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_3a1724();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_3a0164();
    sub_38899c();
    sub_3a0164();
    sub_38899c();
    sub_3a1c5c();
    sub_39e490();
    sub_3a13b4();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39df2c();
    ff_cbs_read_simple_unsigned();
    sub_39e02c();
    sub_39e0b4();
    sub_39f8fc();
    sub_38a0f0();
    sub_39e454();
    sub_38b164();
}
