// Function: FT_Gzip_Uncompress
// RVA: 0xed9594, Size: 276 bytes
int64_t FT_Gzip_Uncompress(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "1.2.8";
    inflateInit2_(...); // call PLT API at 0xed960c
    return a0;
    inflate(...); // call PLT API at 0xed9644
    inflateEnd(...); // call PLT API at 0xed965c
    inflateEnd(...); // call PLT API at 0xed9670
    __stack_chk_fail(...); // call PLT API at 0xed96a4
}
