// Function: MMCodec::PCMTransfer::release()
// RVA: 0x169ee0, Size: 68 bytes
int64_t _ZN7MMCodec11PCMTransfer7releaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x169f00
    av_audio_fifo_free(...); // call imported API via PLT at 0x169f10
    return a0;
}
