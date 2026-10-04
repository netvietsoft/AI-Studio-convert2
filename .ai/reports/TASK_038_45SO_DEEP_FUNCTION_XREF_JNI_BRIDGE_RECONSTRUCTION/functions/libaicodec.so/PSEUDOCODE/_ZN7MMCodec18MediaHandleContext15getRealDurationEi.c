// Function: MMCodec::MediaHandleContext::getRealDuration(int)
// RVA: 0x146594, Size: 260 bytes
int64_t _ZN7MMCodec18MediaHandleContext15getRealDurationEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_init_packet(...); // call imported API via PLT at 0x1465c4
    avformat_seek_file(...); // call imported API via PLT at 0x1465ec
    av_read_frame(...); // call imported API via PLT at 0x1465f8
    av_seek_frame(...); // call imported API via PLT at 0x146614
    return a0;
    av_packet_unref(...); // call imported API via PLT at 0x146648
    av_read_frame(...); // call imported API via PLT at 0x146654
    __stack_chk_fail(...); // call imported API via PLT at 0x146694
}
