// Library: libffmpeg.so
// Function ID: libffmpeg::0x37acc0
// Recovered Name: sub_37acc0
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x37acc0 | Size: 704 bytes | SHA256: ce5191963d39e4e1cc42617749743ede683c3f13b5247c14937dff399fdf1690
// Callers: 0 | Callees: 21 | Imports: 2

// Calls external APIs: av_log, ff_cbs_trace_header
// Strings referenced:
//   "Access Unit Delimiter"
//   "Picture Parameter Set"
//   "Sequence Parameter Set"
//   "cabac_init_present_flag"
//   "constrained_intra_pred_flag"

void sub_37acc0(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 176 instructions
    av_log();
    /* 0x37acc4 */ b #0x37b11c;
    sub_3a1bd0();
    /* 0x37accc */ cmp w3, #0x27;
    /* 0x37acd0 */ ldr x21, [x21, #0x28];
    /* 0x37acd4 */ mov w10, #0x27;
    /* 0x37acd8 */ csel x1, x9, x8, eq;
    /* 0x37acdc */ mov x0, x19;
    /* 0x37ace0 */ cinc w22, w10, ne;
    ff_cbs_trace_header();
    /* 0x37ace8 */ mov x0, x19;
    sub_38be9c();
    sub_39faa4();
    sub_39fa50();
    sub_39e0b4();
    sub_39e7e4();
    sub_38be9c();
    sub_39fb18();
    sub_39e514();
    sub_39de58();
    sub_39de58();
    sub_39e174();
    sub_39de58();
    sub_39de58();
    sub_39e4fc();
    sub_39e4fc();
    sub_3a1c5c();
    sub_3a00a8();
    sub_39de58();
    sub_39de58();
    sub_39de58();
    sub_39df6c();
    sub_39e0b4();
    sub_39e414();
    sub_38be9c();
    sub_39e10c();
    sub_39fd08();
    sub_39e0b4();
    sub_39e7e4();
    sub_38be9c();
    sub_39e164();
    sub_3a132c();
    sub_39e3d8();
    sub_39df08();
}
