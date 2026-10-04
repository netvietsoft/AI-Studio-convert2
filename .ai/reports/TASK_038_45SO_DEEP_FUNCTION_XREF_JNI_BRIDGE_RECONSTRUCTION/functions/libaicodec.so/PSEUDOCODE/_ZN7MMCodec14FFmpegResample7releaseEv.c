// Function: MMCodec::FFmpegResample::release()
// RVA: 0x167340, Size: 44 bytes
int64_t _ZN7MMCodec14FFmpegResample7releaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    swr_free(...); // call imported API via PLT at 0x167354
    return a0;
}
