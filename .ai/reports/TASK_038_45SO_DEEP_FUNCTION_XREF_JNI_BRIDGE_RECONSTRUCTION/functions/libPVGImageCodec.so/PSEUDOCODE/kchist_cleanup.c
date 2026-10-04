// Function: kchist_cleanup
// RVA: 0x290d10, Size: 40 bytes
int64_t kchist_cleanup(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    Gif_Free(...); // call PLT API at 0x290d24
    return a0;
}
