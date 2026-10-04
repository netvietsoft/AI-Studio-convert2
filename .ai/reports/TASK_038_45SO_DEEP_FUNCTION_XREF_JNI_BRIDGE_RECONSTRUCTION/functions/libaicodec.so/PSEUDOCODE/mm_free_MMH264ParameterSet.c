// Function: mm_free_MMH264ParameterSet
// RVA: 0x173ff0, Size: 184 bytes
int64_t mm_free_MMH264ParameterSet(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_free(...); // call imported API via PLT at 0x174028
    av_free(...); // call imported API via PLT at 0x174040
    av_free(...); // call imported API via PLT at 0x174048
    av_free(...); // call imported API via PLT at 0x174068
    av_free(...); // call imported API via PLT at 0x174080
    av_free(...); // call imported API via PLT at 0x174088
    av_free(...); // call imported API via PLT at 0x174090
    return a0;
}
