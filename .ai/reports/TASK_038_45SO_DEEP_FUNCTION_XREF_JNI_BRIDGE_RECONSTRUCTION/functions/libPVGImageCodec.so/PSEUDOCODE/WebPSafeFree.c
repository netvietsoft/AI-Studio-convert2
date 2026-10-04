// Function: WebPSafeFree
// RVA: 0x48b4dc, Size: 68 bytes
int64_t WebPSafeFree(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0x48b510
    return a0;
}
