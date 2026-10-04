// Function: WebPFreeDecBuffer
// RVA: 0x428404, Size: 88 bytes
int64_t WebPFreeDecBuffer(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeFree(...); // call PLT API at 0x42843c
    return a0;
}
