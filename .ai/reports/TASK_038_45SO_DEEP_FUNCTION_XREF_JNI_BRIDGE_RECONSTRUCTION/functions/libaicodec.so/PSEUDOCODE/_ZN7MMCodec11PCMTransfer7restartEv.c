// Function: MMCodec::PCMTransfer::restart()
// RVA: 0x16a9dc, Size: 56 bytes
int64_t _ZN7MMCodec11PCMTransfer7restartEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN7MMCodec10MTResample7restartEv(...); // call imported API via PLT at 0x16a9f4
    av_audio_fifo_reset(...); // call imported API via PLT at 0x16aa00
    return a0;
}
