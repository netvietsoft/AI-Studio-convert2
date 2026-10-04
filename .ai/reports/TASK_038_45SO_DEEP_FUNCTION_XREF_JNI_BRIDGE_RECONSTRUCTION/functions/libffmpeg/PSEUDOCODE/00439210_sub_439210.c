// Library: libffmpeg.so
// Function ID: libffmpeg::0x439210
// Recovered Name: sub_439210
// Visibility: LOCAL_RECOVERED | Confidence: HIGH_CONFIDENCE
// Address: 0x439210 | Size: 3036 bytes | SHA256: 0d0c42554595eb63c99459de60d9cfb97061bf96f4d4d0d5bdffebe3fa8b8d40
// Callers: 0 | Callees: 16 | Imports: 16

// Calls external APIs: __assert2, abort, av_buffer_alloc, av_buffer_unref, av_log, av_shrink_packet, avio_r8, avio_read, avio_rl32, avio_rl64, avio_seek, avio_skip, avpriv_request_sample, ff_asfcrypt_dec, memcpy, memset
// Strings referenced:
//   "Invalid ECC byte"
//   "asf->packet_size_left < FRAME_HEADER_SIZE || asf->packet_segments < 1"
//   "asf_st"
//   "idx + 1 <= asf_st->pkt.size / asf_st->ds_chunk_size"
//   "int asf_read_packet(AVFormatContext *, AVPacket *)"

void sub_439210(uint64_t x0, uint64_t x1, uint64_t x2, uint64_t x3) {
    // Disassembled 759 instructions
    /* 0x439210 */ ldr x26, [sp, #0x28];
    /* 0x439214 */ str wzr, [x22, #0x788];
    /* 0x439218 */ adrp x28, #0xaa000;
    /* 0x43921c */ add x28, x28, #0x78f;
    /* 0x439220 */ str xzr, [x22, #0x7c0];
    /* 0x439224 */ b #0x438ec0;
    /* 0x439228 */ cmp w3, #8;
    /* 0x43922c */ b.lt #0x439280;
    /* 0x439230 */ mov x0, x25;
    sub_43a71c();
    /* 0x439238 */ ldrsw x19, [x29, #0x790];
    sub_43a7c4();
    av_log();
    avio_r8();
    sub_43a738();
    av_log();
    av_log();
    av_log();
    sub_43a738();
    av_log();
    memset();
    avio_read();
    memset();
    av_shrink_packet();
    ff_asfcrypt_dec();
    av_log();
    sub_43a8b0();
    avio_rl32();
    sub_43a7cc();
    sub_43a71c();
    sub_43a7a0();
    sub_43a7a0();
    avio_skip();
    avio_rl64();
    avio_rl64();
    sub_43a778();
    sub_43a738();
    sub_43a738();
    av_log();
    sub_43a778();
    sub_43a880();
    sub_43a738();
    av_log();
    sub_43a7c4();
    sub_43a7cc();
    sub_43a7a0();
    sub_43a738();
    av_log();
    sub_43a738();
    av_log();
    av_log();
    avio_skip();
    sub_43a71c();
    sub_43a758();
    sub_43a758();
    sub_43a868();
    sub_43a738();
    av_log();
    sub_43a758();
    sub_43a758();
    sub_43a868();
    sub_43a71c();
    sub_43a738();
    av_log();
    sub_43a868();
    avio_seek();
    sub_43a758();
    sub_43a758();
    avio_seek();
    avpriv_request_sample();
    sub_43a758();
    sub_43a758();
    sub_43a808();
    sub_43a810();
    sub_43a758();
    sub_43a808();
    sub_43a810();
    sub_43a758();
    sub_43a808();
    sub_43a810();
    sub_43a758();
    sub_43a71c();
    sub_43a738();
    sub_43a808();
    sub_43a810();
    sub_43a71c();
    sub_43a738();
    av_log();
    sub_43a758();
    sub_43a818();
    avio_seek();
    sub_43a738();
    av_log();
    av_log();
    return x0;
    av_buffer_alloc();
    memcpy();
    sub_43a738();
    av_log();
    av_buffer_unref();
    memcpy();
    sub_43a88c();
    av_log();
    abort();
    sub_43a7a8();
    __assert2();
    __assert2();
    sub_43a7a8();
    __assert2();
    sub_43a7a8();
    __assert2();
    sub_43a65c();
    return x0;
}
