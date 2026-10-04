// Library: libffmpeg.so
// Function ID: libffmpeg::0x37ab8c
// Recovered Name: sub_37ab8c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37ab8c | Size: 304 bytes | SHA256: 14ef27b2631e7bad9b69a066a5f95739837d55bb974e47f6462596e6d71c4960
// Callers: 0 | Callees: 6 | Imports: 0

// Strings referenced:
//   "Slice Segment Header"
//   "dependent_slice_segment_flag"
//   "first_slice_segment_in_pic_flag"
//   "no_output_of_prior_pics_flag"
//   "slice_pic_parameter_set_id"

void sub_37ab8c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 76 instructions
    /* 0x37ab8c */ stp x29, x30, [sp, #0xd0];
    /* 0x37ab90 */ stp x28, x27, [sp, #0xe0];
    /* 0x37ab94 */ stp x26, x25, [sp, #0xf0];
    /* 0x37ab98 */ stp x24, x23, [sp, #0x100];
    /* 0x37ab9c */ stp x22, x21, [sp, #0x110];
    /* 0x37aba0 */ stp x20, x19, [sp, #0x120];
    /* 0x37aba4 */ ldr w3, [x1];
    /* 0x37aba8 */ mov x19, x0;
    /* 0x37abac */ cmp w3, #0x28;
    /* 0x37abb0 */ b.hi #0x37b100;
    /* 0x37abb4 */ adrp x8, #0x125000;
    sub_39e0b4();
    sub_39e414();
    sub_38be9c();
    sub_39de58();
    sub_39de58();
    sub_39fb18();
    sub_39debc();
}
