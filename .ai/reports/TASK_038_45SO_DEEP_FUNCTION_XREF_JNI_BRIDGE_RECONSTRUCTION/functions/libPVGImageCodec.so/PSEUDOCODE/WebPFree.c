// Function: WebPFree
// RVA: 0x48b548, Size: 36 bytes
int64_t WebPFree(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeFree(...); // call PLT API at 0x48b55c
    return a0;
}
