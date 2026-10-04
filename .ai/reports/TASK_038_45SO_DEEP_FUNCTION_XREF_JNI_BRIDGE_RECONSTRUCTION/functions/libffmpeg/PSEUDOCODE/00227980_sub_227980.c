// Library: libffmpeg.so
// Function ID: libffmpeg::0x227980
// Recovered Name: sub_227980
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x227980 | Size: 2220 bytes | SHA256: 2ebbaf406913624efe731daa2f8b5bd02fa24233258cf40a4912d7305a824da9
// Callers: 0 | Callees: 36 | Imports: 4

// Calls external APIs: abort, av_log, ff_cbs_write_simple_unsigned, ff_cbs_write_unsigned
// Strings referenced:
//   "allow_high_precision_mv"
//   "base_q_idx"
//   "color_space"
//   "delta_q_uv_ac.delta_coded"
//   "delta_q_uv_ac.delta_q"

void sub_227980(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 555 instructions
    sub_229498();
    /* 0x227984 */ ldp x29, x30, [sp, #0x70];
    /* 0x227988 */ b #0x2297a4;
    sub_2296c4();
    /* 0x227990 */ tbnz w0, #0x1f, #0x227980;
    /* 0x227994 */ ldr w3, [x25];
    sub_2295ec();
    /* 0x22799c */ tbnz w0, #0x1f, #0x227980;
    sub_2294d0();
    /* 0x2279a4 */ tbnz w0, #0x1f, #0x227980;
    sub_2294e0();
    av_log();
    sub_229220();
    sub_2292f4();
    sub_229318();
    sub_2293f8();
    sub_2296c4();
    sub_2295ec();
    sub_2294b0();
    sub_22958c();
    sub_229744();
    ff_cbs_write_unsigned();
    sub_2295e0();
    sub_22939c();
    sub_2292f4();
    sub_229354();
    sub_2292f4();
    sub_229354();
    sub_22971c();
    sub_229324();
    sub_229268();
    sub_2292f4();
    sub_229354();
    sub_2294b0();
    sub_2294d0();
    sub_2294e0();
    sub_2292f4();
    sub_229318();
    sub_2292f4();
    sub_229354();
    sub_229220();
    sub_229220();
    sub_2293f8();
    ff_cbs_write_simple_unsigned();
    sub_2295fc();
    sub_229220();
    sub_229220();
    sub_2295c4();
    sub_229324();
    sub_229578();
    sub_2294d0();
    sub_2294e0();
    sub_229220();
    sub_229220();
    sub_2293f8();
    sub_2295a8();
    sub_229324();
    sub_229578();
    sub_2294b0();
    sub_229480();
    sub_229458();
    sub_229408();
    sub_229480();
    sub_229458();
    sub_229408();
    sub_229480();
    sub_229458();
    sub_229408();
    sub_229220();
    sub_229220();
    sub_22960c();
    sub_229368();
    sub_2297ac();
    sub_229564();
    ff_cbs_write_unsigned();
    sub_2295e0();
    ff_cbs_write_simple_unsigned();
    sub_2295e0();
    sub_2297ac();
    ff_cbs_write_unsigned();
    av_log();
    sub_229220();
    sub_229220();
    sub_2295e0();
    sub_22939c();
    sub_2296b8();
    ff_cbs_write_unsigned();
    av_log();
    av_log();
    sub_2296b8();
    sub_22939c();
    sub_229730();
    sub_2296b8();
    sub_2290cc();
    sub_2296b8();
    sub_2290cc();
    sub_2294c0();
    sub_2293a8();
    sub_229544();
    sub_2296e4();
    av_log();
    abort();
}
