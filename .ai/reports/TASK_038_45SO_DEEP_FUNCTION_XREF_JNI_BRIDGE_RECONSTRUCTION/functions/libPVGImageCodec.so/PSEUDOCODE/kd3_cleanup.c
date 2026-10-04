// Function: kd3_cleanup
// RVA: 0x29279c, Size: 48 bytes
int64_t kd3_cleanup(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_Free(...); // call PLT API at 0x2927b0
    Gif_Free(...); // call PLT API at 0x2927b8
    Gif_Free(...); // call PLT API at 0x2927c8
}
