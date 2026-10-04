// Function: mm_decode_h264_packet_parameter
// RVA: 0x1741f0, Size: 444 bytes
int64_t mm_decode_h264_packet_parameter(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    av_realloc_array(...); // call imported API via PLT at 0x174250
    av_realloc_array(...); // call imported API via PLT at 0x174264
    av_malloc(...); // call imported API via PLT at 0x174280
    memcpy(...); // call imported API via PLT at 0x174290
    av_realloc_array(...); // call imported API via PLT at 0x17431c
    av_realloc_array(...); // call imported API via PLT at 0x174330
    av_malloc(...); // call imported API via PLT at 0x17434c
    memcpy(...); // call imported API via PLT at 0x17435c
    return a0;
}
