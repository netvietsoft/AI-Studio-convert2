// Library: libffmpeg.so
// Function ID: libffmpeg::0x3774ac
// Recovered Name: sub_3774ac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x3774ac | Size: 196 bytes | SHA256: b2604af52feceb3f0c319196104285477ebb2c6ae5baeb5f6d33ed26242f88db
// Callers: 0 | Callees: 5 | Imports: 0

// Strings referenced:
//   "colour_plane_id"
//   "dependent_slice_segment_flag"
//   "pic_output_flag"
//   "slice_type"

void sub_3774ac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 49 instructions
    /* 0x3774ac */ mov w23, #0xb1b7;
    /* 0x3774b0 */ movk w23, #0xbebb, lsl #16;
    /* 0x3774b4 */ b #0x37917c;
    /* 0x3774b8 */ ldrb w8, [x29, #5];
    /* 0x3774bc */ ldrh w26, [x22, #0x1b2];
    /* 0x3774c0 */ cbz w8, #0x3775a8;
    /* 0x3774c4 */ adrp x3, #0xcf000;
    /* 0x3774c8 */ add x3, x3, #0xdff;
    /* 0x3774cc */ add x1, sp, #0x28;
    /* 0x3774d0 */ add x4, sp, #0xd0;
    sub_39dea8();
    sub_39dff8();
    sub_38899c();
    sub_39dea8();
    sub_39f908();
    sub_39e454();
}
