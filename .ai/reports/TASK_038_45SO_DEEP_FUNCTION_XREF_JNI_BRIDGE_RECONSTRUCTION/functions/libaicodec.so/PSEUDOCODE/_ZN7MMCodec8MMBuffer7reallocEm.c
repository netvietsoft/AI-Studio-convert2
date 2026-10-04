// Function: MMCodec::MMBuffer::realloc(unsigned long)
// RVA: 0x168ee8, Size: 256 bytes
int64_t _ZN7MMCodec8MMBuffer7reallocEm(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_free(...); // call imported API via PLT at 0x168f1c
    av_fast_malloc(...); // call imported API via PLT at 0x168f30
    return a0;
    const char* s_7d752 = "MTMV_AICodec"; // string xref
    const char* s_6a5ef = "[%s(%d)]:> alloc buffer failed"; // string xref
    const char* s_6c72d = "realloc"; // string xref
    __android_log_print(...); // call imported API via PLT at 0x168f94
    const char* s_75714 = "%s/MTMV_AICodec: [%s(%d)]:> alloc buffer failed
"; // string xref
    const char* s_6c72d = "realloc"; // string xref
    _ZN7MMCodec13AICodecGlobal12log_callbackEiPKcz(...); // call imported API via PLT at 0x168fd0
    return a0;
}
