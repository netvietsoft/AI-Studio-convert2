// Function: MMCodec::MMBuffer::release()
// RVA: 0x169030, Size: 52 bytes
int64_t _ZN7MMCodec8MMBuffer7releaseEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_free(...); // call imported API via PLT at 0x169050
    return a0;
}
