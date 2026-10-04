// Function: WebPMemoryWriterClear
// RVA: 0x44f728, Size: 80 bytes
int64_t WebPMemoryWriterClear(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeFree(...); // call PLT API at 0x44f74c
    return a0;
}
