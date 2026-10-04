// Function: MMCodec::makeErrorStr(int)
// RVA: 0x162f18, Size: 48 bytes
int64_t _ZN7MMCodec12makeErrorStrEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_strerror(...); // call imported API via PLT at 0x162f34
    return a0;
}
