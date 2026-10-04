// Library: libffmpeg.so
// Function ID: libffmpeg::0x37b11c
// Recovered Name: sub_37b11c
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37b11c | Size: 332 bytes | SHA256: cb615868646e0488f4a0115281486be48debf50a1ea8d81f87c531048140c531
// Callers: 0 | Callees: 9 | Imports: 1

// Calls external APIs: ff_cbs_write_unsigned
// Strings referenced:
//   "colour_plane_id"
//   "dependent_slice_segment_flag"
//   "pic_output_flag"
//   "slice_reserved_flag[i]"
//   "slice_segment_address"

void sub_37b11c(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 83 instructions
    sub_39e558();
    /* 0x37b120 */ b #0x37e810;
    /* 0x37b124 */ ldrb w8, [x29, #5];
    /* 0x37b128 */ ldrh w25, [x23, #0x1b2];
    /* 0x37b12c */ ldrb w4, [x21, #6];
    /* 0x37b130 */ cbz w8, #0x37b148;
    /* 0x37b134 */ adrp x3, #0xcf000;
    /* 0x37b138 */ add x3, x3, #0xdff;
    sub_39de58();
    /* 0x37b140 */ tbz w0, #0x1f, #0x37b14c;
    /* 0x37b144 */ b #0x37e80c;
    sub_39df4c();
    sub_3a1d9c();
    ff_cbs_write_unsigned();
    sub_3a10c8();
    sub_39def0();
    ff_cbs_write_unsigned();
    sub_39f100();
    sub_39e52c();
    sub_39de58();
    sub_39e10c();
}
