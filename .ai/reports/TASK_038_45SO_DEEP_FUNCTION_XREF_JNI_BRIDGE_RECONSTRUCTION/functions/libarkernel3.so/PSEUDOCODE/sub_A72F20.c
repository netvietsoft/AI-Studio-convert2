// Function: sub_A72F20
// RVA: 0xa72f20, Size: 888 bytes
int64_t sub_A72F20(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_packet_alloc(...); // call imported API via PLT at 0xa72f54
    av_frame_alloc(...); // call imported API via PLT at 0xa72f5c
    av_rescale_q_rnd(...); // call imported API via PLT at 0xa72f94
    const char* s_1f1970 = "updateFrameThread"; // string xref
    av_seek_frame(...); // call imported API via PLT at 0xa7300c
    const char* s_199bc4 = "mtlabar3"; // string xref
    const char* s_242009 = "Could not seek video, pts:%d"; // string xref
    sub_CCCFE0(...); // call internal func at 0xa73030
    avcodec_flush_buffers(...); // call imported API via PLT at 0xa7303c
    av_packet_unref(...); // call imported API via PLT at 0xa73050
    av_read_frame(...); // call imported API via PLT at 0xa7305c
    avcodec_send_packet(...); // call imported API via PLT at 0xa7307c
    av_strerror(...); // call imported API via PLT at 0xa7308c
    const char* s_199bc4 = "mtlabar3"; // string xref
    const char* s_278e37 = "Could not send packet for decoding, %s"; // string xref
    sub_CCCFE0(...); // call internal func at 0xa730ac
    av_frame_unref(...); // call imported API via PLT at 0xa730c4
    avcodec_receive_frame(...); // call imported API via PLT at 0xa730d0
    sub_A733A4(...); // call internal func at 0xa730ec
    sub_A72624(...); // call internal func at 0xa73104
    av_frame_unref(...); // call imported API via PLT at 0xa73120
    av_frame_move_ref(...); // call imported API via PLT at 0xa7312c
    sub_A72724(...); // call internal func at 0xa73138
    const char* s_199bc4 = "mtlabar3"; // string xref
    const char* s_1f1982 = "DecoderFrame Could not receive frame"; // string xref
    sub_CCCFE0(...); // call internal func at 0xa731c4
    const char* s_199bc4 = "mtlabar3"; // string xref
    const char* s_1f1970 = "updateFrameThread"; // string xref
    const char* s_2108c1 = "Could not read frame"; // string xref
    sub_CCCFE0(...); // call internal func at 0xa7322c
    sub_A72724(...); // call internal func at 0xa7323c
    av_frame_free(...); // call imported API via PLT at 0xa73244
    av_packet_free(...); // call imported API via PLT at 0xa7324c
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xa73284
    sub_562D14(...); // call internal func at 0xa73288
    sub_562D14(...); // call internal func at 0xa7328c
    sub_562D14(...); // call internal func at 0xa73290
    sub_562D14(...); // call internal func at 0xa73294
}
