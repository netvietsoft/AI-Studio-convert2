// Function: sub_1743C8
// RVA: 0x1743c8, Size: 352 bytes
int64_t sub_1743C8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_realloc_array(...); // call imported API via PLT at 0x1743fc
    av_realloc_array(...); // call imported API via PLT at 0x174410
    av_malloc(...); // call imported API via PLT at 0x174440
    memcpy(...); // call imported API via PLT at 0x17445c
    av_realloc_array(...); // call imported API via PLT at 0x174484
    av_realloc_array(...); // call imported API via PLT at 0x174498
    av_malloc(...); // call imported API via PLT at 0x1744c8
    memcpy(...); // call imported API via PLT at 0x1744ec
    return a0;
}
