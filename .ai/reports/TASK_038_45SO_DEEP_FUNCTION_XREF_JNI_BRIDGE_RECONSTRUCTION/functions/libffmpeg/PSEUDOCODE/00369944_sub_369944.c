// Library: libffmpeg.so
// Function ID: libffmpeg::0x369944
// Recovered Name: sub_369944
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x369944 | Size: 2536 bytes | SHA256: 96ea3227822959e1ae51c3a1d8306dfb4235e038615522926a2e03b5497638c0
// Callers: 0 | Callees: 20 | Imports: 3

// Calls external APIs: abort, av_buffer_ref, av_log
// Strings referenced:
//   "base_qindex"
//   "clamping_type"
//   "coeff_prob[i][j][k][l]"
//   "coeff_prob_update[i][j][k][l]"
//   "color_space"

void sub_369944(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 634 instructions
    /* 0x369944 */ ldp x20, x19, [sp, #0xe0];
    /* 0x369948 */ ldp x22, x21, [sp, #0xd0];
    /* 0x36994c */ ldp x24, x23, [sp, #0xc0];
    /* 0x369950 */ ldp x26, x25, [sp, #0xb0];
    /* 0x369954 */ ldp x28, x27, [sp, #0xa0];
    /* 0x369958 */ ldp x29, x30, [sp, #0x90];
    /* 0x36995c */ add sp, sp, #0xf0;
    return x0;
    /* 0x369964 */ adrp x3, #0x9a000;
    /* 0x369968 */ add x3, x3, #0xbee;
    sub_36a898();
    sub_36a32c();
    sub_36a898();
    sub_36a32c();
    sub_36a898();
    sub_36a32c();
    sub_36a904();
    sub_36a32c();
    sub_36a8e8();
    sub_36a32c();
    sub_36a904();
    sub_36a32c();
    sub_36a8e8();
    sub_36a32c();
    sub_36a7cc();
    sub_36a85c();
    sub_36a470();
    sub_36a7fc();
    sub_36a920();
    sub_36a7fc();
    sub_36a950();
    sub_36a470();
    sub_36a7cc();
    sub_36a968();
    sub_36a874();
    sub_36a470();
    sub_36a968();
    sub_36a874();
    sub_36a470();
    sub_36a85c();
    sub_36a470();
    sub_36a838();
    sub_36a7fc();
    sub_36a6dc();
    sub_36a7fc();
    sub_36a920();
    sub_36a7ec();
    sub_36a968();
    sub_36a874();
    sub_36a470();
    sub_36a8ac();
    sub_36a470();
    sub_36a844();
    sub_36a818();
    sub_36a844();
    sub_36a818();
    sub_36a844();
    sub_36a818();
    sub_36a844();
    sub_36a818();
    sub_36a844();
    sub_36a7cc();
    sub_36a85c();
    sub_36a470();
    sub_36a7ec();
    sub_36a7ec();
    sub_36a7cc();
    sub_36a85c();
    sub_36a470();
    sub_36a7cc();
    sub_36a7cc();
    sub_36a838();
    sub_36a950();
    sub_36a470();
    sub_36a7cc();
    sub_36a7ec();
    sub_36a7ec();
    sub_36a874();
    sub_36a470();
    sub_36a874();
    sub_36a470();
    sub_36a8ac();
    sub_36a470();
    sub_36a934();
    sub_36a470();
    sub_36a884();
    av_log();
    abort();
    sub_36a818();
    sub_36a934();
    sub_36a470();
    sub_36a7fc();
    sub_36a470();
    av_buffer_ref();
    sub_36a884();
    av_log();
    abort();
}
