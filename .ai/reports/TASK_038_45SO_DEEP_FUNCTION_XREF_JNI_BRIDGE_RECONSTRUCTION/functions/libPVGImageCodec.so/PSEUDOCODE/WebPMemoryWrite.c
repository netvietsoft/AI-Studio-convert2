// Function: WebPMemoryWrite
// RVA: 0x44f548, Size: 480 bytes
int64_t WebPMemoryWrite(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeMalloc(...); // call PLT API at 0x44f608
    __memcpy_chk(...); // call PLT API at 0x44f670
    WebPSafeFree(...); // call PLT API at 0x44f680
    __memcpy_chk(...); // call PLT API at 0x44f6f0
    return a0;
}
