// Function: MMCodec::HLSMuxer::~HLSMuxer()
// RVA: 0xd9ad8, Size: 388 bytes
int64_t _ZN7MMCodec8HLSMuxerD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    avformat_free_context(...); // call imported API via PLT at 0xd9af0
    free(...); // call imported API via PLT at 0xd9b14
    avformat_free_context(...); // call imported API via PLT at 0xd9b30
    free(...); // call imported API via PLT at 0xd9b54
    avformat_free_context(...); // call imported API via PLT at 0xd9b70
    free(...); // call imported API via PLT at 0xd9b94
    avformat_free_context(...); // call imported API via PLT at 0xd9bb0
    free(...); // call imported API via PLT at 0xd9bd4
    (*x8)(...); // indirect call at 0xd9c14
    (*x8)(...); // indirect call at 0xd9c44
    _ZN7MMCodec8MMBufferD1Ev(...); // call imported API via PLT at 0xd9c54
    sub_CEBC4(...); // call internal func at 0xd9c58
}
