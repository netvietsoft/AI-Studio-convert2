// Library: libffmpeg.so
// Function ID: libffmpeg::0x226dac
// Recovered Name: sub_226dac
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x226dac | Size: 2468 bytes | SHA256: e5dcfa8bec7d3fb82bfc4751f192c3c90b2ffe5f64fd3862d04daf9cfd75afb9
// Callers: 0 | Callees: 33 | Imports: 5

// Calls external APIs: abort, av_buffer_ref, av_log, ff_cbs_read_simple_unsigned, ff_cbs_read_unsigned
// Strings referenced:
//   "allow_high_precision_mv"
//   "base_q_idx"
//   "delta_q_uv_ac.delta_coded"
//   "delta_q_uv_ac.delta_q"
//   "delta_q_uv_dc.delta_coded"

void sub_226dac(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 617 instructions
    /* 0x226dac */ ldr w8, [sp, #0x28];
    /* 0x226db0 */ tst w8, #7;
    /* 0x226db4 */ b.eq #0x226e68;
    /* 0x226db8 */ adrp x3, #0xc0000;
    /* 0x226dbc */ add x3, x3, #0xa1f;
    /* 0x226dc0 */ add x1, sp, #0x18;
    /* 0x226dc4 */ add x5, sp, #0x60;
    /* 0x226dc8 */ mov x0, x20;
    sub_229430();
    /* 0x226dd0 */ tbz w0, #0x1f, #0x226dac;
    /* 0x226dd4 */ b #0x226ddc;
    sub_229698();
    return x0;
    sub_2292d4();
    sub_229304();
    ff_cbs_read_simple_unsigned();
    sub_229304();
    ff_cbs_read_simple_unsigned();
    av_buffer_ref();
    sub_229710();
    sub_229634();
    sub_229624();
    sub_2294f0();
    sub_2292d4();
    sub_229340();
    sub_229710();
    sub_229634();
    sub_229444();
    sub_22958c();
    sub_2296f8();
    sub_229744();
    ff_cbs_read_unsigned();
    sub_2296f8();
    ff_cbs_read_unsigned();
    sub_229444();
    sub_228850();
    sub_2294f0();
    sub_229340();
    ff_cbs_read_simple_unsigned();
    ff_cbs_read_simple_unsigned();
    sub_229460();
    ff_cbs_read_simple_unsigned();
    sub_2292e8();
    sub_2295c4();
    sub_229500();
    sub_229684();
    sub_228998();
    sub_22971c();
    sub_229500();
    sub_229268();
    sub_2292d4();
    sub_229304();
    ff_cbs_read_simple_unsigned();
    sub_229624();
    sub_2294f0();
    sub_2292d4();
    sub_229304();
    ff_cbs_read_simple_unsigned();
    sub_229340();
    sub_2295a8();
    sub_229368();
    ff_cbs_read_unsigned();
    sub_229684();
    sub_228998();
    sub_229444();
    sub_22937c();
    ff_cbs_read_unsigned();
    sub_2293d4();
    sub_22937c();
    ff_cbs_read_unsigned();
    sub_2293d4();
    sub_22937c();
    ff_cbs_read_unsigned();
    sub_2293d4();
    sub_229460();
    ff_cbs_read_simple_unsigned();
    sub_2292e8();
    sub_22960c();
    sub_229368();
    ff_cbs_read_unsigned();
    sub_229564();
    ff_cbs_read_unsigned();
    sub_229460();
    ff_cbs_read_simple_unsigned();
    sub_229368();
    ff_cbs_read_unsigned();
    sub_229564();
    ff_cbs_read_unsigned();
    sub_2292e8();
    sub_2292e8();
    sub_229368();
    ff_cbs_read_unsigned();
    ff_cbs_read_unsigned();
    sub_229460();
    ff_cbs_read_unsigned();
    sub_229730();
    sub_2296f8();
    sub_228aa0();
    sub_2296f8();
    sub_228aa0();
    ff_cbs_read_simple_unsigned();
    sub_2293a8();
    sub_229544();
    sub_229254();
    av_log();
    abort();
}
