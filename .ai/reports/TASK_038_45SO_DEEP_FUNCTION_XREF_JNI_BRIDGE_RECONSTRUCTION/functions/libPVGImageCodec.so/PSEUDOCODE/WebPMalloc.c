// Function: WebPMalloc
// RVA: 0x48b520, Size: 40 bytes
int64_t WebPMalloc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeMalloc(...); // call PLT API at 0x48b538
    return a0;
}
