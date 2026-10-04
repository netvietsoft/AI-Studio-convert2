// Function: MMCodec::SWDecoder::sendPacket(AVPacket*)
// RVA: 0x149144, Size: 232 bytes
int64_t _ZN7MMCodec9SWDecoder10sendPacketEP8AVPacket(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec8protocol14parseFrameTypeEPhiiRiS2_(...); // call imported API via PLT at 0x1491b4
    avcodec_send_packet(...); // call imported API via PLT at 0x1491fc
    _ZN7MMCodec23getErrorCodeWithAVErrorEi(...); // call imported API via PLT at 0x149200
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x149228
}
