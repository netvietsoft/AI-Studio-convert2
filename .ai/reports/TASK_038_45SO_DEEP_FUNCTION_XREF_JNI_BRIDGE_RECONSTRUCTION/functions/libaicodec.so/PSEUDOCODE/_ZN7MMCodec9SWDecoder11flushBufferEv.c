// Function: MMCodec::SWDecoder::flushBuffer()
// RVA: 0x1495b4, Size: 244 bytes
int64_t _ZN7MMCodec9SWDecoder11flushBufferEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_85538 = "h264_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0x1495f8
    const char* s_74948 = "hevc_qsv"; // string xref
    strcmp(...); // call imported API via PLT at 0x14960c
    av_packet_alloc(...); // call imported API via PLT at 0x149614
    avcodec_send_packet(...); // call imported API via PLT at 0x14962c
    av_frame_alloc(...); // call imported API via PLT at 0x149634
    avcodec_receive_frame(...); // call imported API via PLT at 0x149650
    av_frame_free(...); // call imported API via PLT at 0x149660
    av_packet_free(...); // call imported API via PLT at 0x149668
    avcodec_flush_buffers(...); // call imported API via PLT at 0x149674
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1496a4
}
