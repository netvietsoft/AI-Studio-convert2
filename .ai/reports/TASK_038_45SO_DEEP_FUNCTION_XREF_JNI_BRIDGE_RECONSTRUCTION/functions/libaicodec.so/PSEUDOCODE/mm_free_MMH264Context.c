// Function: mm_free_MMH264Context
// RVA: 0x173604, Size: 148 bytes
int64_t mm_free_MMH264Context(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_free(...); // call imported API via PLT at 0x173664
    av_free(...); // call imported API via PLT at 0x173678
    av_free(...); // call imported API via PLT at 0x173680
    return a0;
}
