// Library: libffmpeg.so
// Function ID: libffmpeg::0x37cbd0
// Recovered Name: sub_37cbd0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37cbd0 | Size: 2812 bytes | SHA256: 691217e15e4c67aea754b0ece5a69a4df803f61a8c7b00a297b68bc5eddafe71
// Callers: 0 | Callees: 50 | Imports: 2

// Calls external APIs: ff_cbs_write_simple_unsigned, ff_cbs_write_unsigned
// Strings referenced:
//   "aspect_ratio_idc"
//   "aspect_ratio_info_present_flag"
//   "cb_qp_offset_list[i]"
//   "chroma_loc_info_present_flag"
//   "chroma_offset_l0[i][j]"

void sub_37cbd0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 703 instructions
    sub_39df08();
    /* 0x37cbd4 */ adrp x3, #0xa7000;
    /* 0x37cbd8 */ add x3, x3, #0x4c0;
    /* 0x37cbdc */ b #0x37bce4;
    /* 0x37cbe0 */ mov w8, #0xe9f8;
    sub_3a18f4();
    /* 0x37cbe8 */ movk w8, #0x78, lsl #16;
    sub_39df4c();
    /* 0x37cbf0 */ ldrb w4, [x23, x8];
    sub_39de8c();
    /* 0x37cbf8 */ tbnz w0, #0x1f, #0x37e80c;
    sub_39df4c();
    sub_38ce64();
    sub_39fd08();
    sub_39e1ac();
    sub_389fe4();
    sub_39de74();
    sub_39e2f8();
    sub_39e2f8();
    sub_39de58();
    sub_39de74();
    sub_39de58();
    sub_39de58();
    sub_39de58();
    sub_39de58();
    sub_39e26c();
    sub_39debc();
    sub_39debc();
    sub_3a217c();
    sub_389770();
    sub_39f100();
    sub_39debc();
    sub_39e544();
    sub_39dfa4();
    sub_389770();
    sub_39df4c();
    sub_3a1ecc();
    sub_3a0788();
    sub_39def0();
    ff_cbs_write_unsigned();
    sub_3a1f20();
    sub_39def0();
    ff_cbs_write_unsigned();
    sub_39ee70();
    sub_3a217c();
    sub_389770();
    sub_39f100();
    sub_39de74();
    sub_39e4d4();
    sub_39debc();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39e08c();
    sub_39ed78();
    ff_cbs_write_simple_unsigned();
    sub_39ed78();
    ff_cbs_write_simple_unsigned();
    sub_39de74();
    sub_3a0454();
    sub_3a1170();
    sub_3a0130();
    sub_39def0();
    ff_cbs_write_unsigned();
    sub_39f10c();
    sub_39e2f8();
    sub_39e2f8();
    sub_39df4c();
    sub_39e158();
    sub_3898ec();
    sub_3a1aa4();
    sub_39f9b8();
    sub_39df4c();
    sub_39e158();
    sub_3898ec();
    sub_39f9b8();
    sub_39ee70();
    sub_39de74();
    sub_39debc();
    sub_39debc();
    sub_39de58();
    sub_3a21c4();
    sub_39de58();
    sub_39e080();
    sub_39e010();
    sub_39de58();
    sub_39de58();
    sub_39de58();
    sub_39de58();
    sub_39de58();
    sub_39de58();
    sub_39e164();
    sub_39e0dc();
    sub_39de58();
    sub_39de58();
    sub_39df6c();
    sub_39e854();
    sub_39e2e4();
    sub_3898ec();
    sub_39ed88();
    sub_39e2e4();
    sub_3898ec();
    sub_3a0494();
    sub_39debc();
    sub_39debc();
    sub_3a04b4();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39e174();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39e08c();
    sub_39ea2c();
    ff_cbs_write_simple_unsigned();
    sub_39ea2c();
    ff_cbs_write_simple_unsigned();
    sub_39e4d4();
    sub_39debc();
    sub_3a04f4();
    sub_39dee0();
    ff_cbs_write_simple_unsigned();
    sub_39e854();
    sub_39dfa4();
    sub_39e954();
}
