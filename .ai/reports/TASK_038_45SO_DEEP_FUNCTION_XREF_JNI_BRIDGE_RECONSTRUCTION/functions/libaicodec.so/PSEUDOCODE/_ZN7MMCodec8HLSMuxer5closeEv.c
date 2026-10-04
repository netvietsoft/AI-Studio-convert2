// Function: MMCodec::HLSMuxer::close()
// RVA: 0xda020, Size: 656 bytes
int64_t _ZN7MMCodec8HLSMuxer5closeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_write_trailer(...); // call imported API via PLT at 0xda038
    avio_closep(...); // call imported API via PLT at 0xda050
    _ZdlPv(...); // call imported API via PLT at 0xda0a8
    avformat_free_context(...); // call imported API via PLT at 0xda0b0
    av_write_trailer(...); // call imported API via PLT at 0xda0c8
    avio_closep(...); // call imported API via PLT at 0xda0e0
    _ZdlPv(...); // call imported API via PLT at 0xda138
    avformat_free_context(...); // call imported API via PLT at 0xda140
    av_write_trailer(...); // call imported API via PLT at 0xda158
    avio_closep(...); // call imported API via PLT at 0xda170
    _ZdlPv(...); // call imported API via PLT at 0xda1c8
    avformat_free_context(...); // call imported API via PLT at 0xda1d0
    av_write_trailer(...); // call imported API via PLT at 0xda1e8
    avio_closep(...); // call imported API via PLT at 0xda200
    _ZdlPv(...); // call imported API via PLT at 0xda258
    avformat_free_context(...); // call imported API via PLT at 0xda260
    free(...); // call imported API via PLT at 0xda278
    (*x8)(...); // indirect call at 0xda29c
    return a0;
}
