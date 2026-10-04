// Library: libffmpeg.so
// Function ID: libffmpeg::0x37d6cc
// Recovered Name: sub_37d6cc
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37d6cc | Size: 1740 bytes | SHA256: c36575b9d918eb441e912f2912a63a76d69814390f8ef671218a258e9bd12964
// Callers: 0 | Callees: 31 | Imports: 2

// Calls external APIs: ff_cbs_write_simple_unsigned, ff_cbs_write_unsigned
// Strings referenced:
//   "bitstream_restriction_flag"
//   "def_disp_win_bottom_offset"
//   "def_disp_win_left_offset"
//   "def_disp_win_right_offset"
//   "def_disp_win_top_offset"

void sub_37d6cc(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 435 instructions
    /* 0x37d6cc */ ldr x8, [sp, #0x18];
    /* 0x37d6d0 */ adrp x3, #0x98000;
    /* 0x37d6d4 */ add x3, x3, #0x21a;
    sub_39dee0();
    /* 0x37d6dc */ ldrb w4, [x8, #0x7a];
    ff_cbs_write_simple_unsigned();
    /* 0x37d6e4 */ tbnz w0, #0x1f, #0x37e80c;
    /* 0x37d6e8 */ ldr x8, [sp, #0x18];
    /* 0x37d6ec */ adrp x3, #0xda000;
    /* 0x37d6f0 */ add x3, x3, #0x351;
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dfa4();
    sub_39e948();
    sub_39dfa4();
    sub_39e948();
    sub_39dfa4();
    sub_39e948();
    sub_39dfa4();
    sub_39e948();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39e348();
    sub_39e348();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39e038();
    sub_389770();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_38caa0();
    sub_39e544();
    sub_39de58();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_3a0dc8();
    sub_39dfa4();
    sub_389770();
    sub_39dfa4();
    sub_39e4c8();
    sub_39dfa4();
    sub_39e4c8();
    sub_39dfa4();
    sub_39e4c8();
    sub_39dfa4();
    sub_39e4c8();
    sub_39df08();
    sub_3a1f4c();
    sub_3a03b4();
    sub_3a02f4();
    sub_3a21b0();
    sub_389770();
    sub_3a21b0();
    sub_389770();
    sub_39df4c();
    sub_39de8c();
    sub_39de58();
    sub_39f17c();
    sub_39df6c();
    sub_3a0a70();
    sub_3a0afc();
    ff_cbs_write_unsigned();
    sub_39def0();
    ff_cbs_write_unsigned();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_39defc();
    sub_39def0();
    ff_cbs_write_unsigned();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_39df4c();
    sub_39e93c();
    sub_3898ec();
    sub_3a10c8();
    sub_39defc();
    sub_3a130c();
    sub_39df4c();
    sub_39effc();
    sub_389770();
    sub_39effc();
    sub_389770();
    sub_39df4c();
    sub_3a139c();
    sub_389770();
    sub_3a139c();
    sub_389770();
    sub_3a0474();
}
