// Function: MMCodec::VideoFrameUtils::release()
// RVA: 0x165f18, Size: 72 bytes
int64_t _ZN7MMCodec15VideoFrameUtils7releaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call imported API via PLT at 0x165f30
    free(...); // call imported API via PLT at 0x165f40
    return a0;
}
