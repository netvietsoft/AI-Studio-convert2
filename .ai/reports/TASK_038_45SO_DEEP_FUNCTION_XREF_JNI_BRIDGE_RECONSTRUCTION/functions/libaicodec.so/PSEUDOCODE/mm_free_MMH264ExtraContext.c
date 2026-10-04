// Function: mm_free_MMH264ExtraContext
// RVA: 0x1736b8, Size: 64 bytes
int64_t mm_free_MMH264ExtraContext(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_free(...); // call imported API via PLT at 0x1736dc
    av_free(...); // call imported API via PLT at 0x1736e4
    return a0;
}
