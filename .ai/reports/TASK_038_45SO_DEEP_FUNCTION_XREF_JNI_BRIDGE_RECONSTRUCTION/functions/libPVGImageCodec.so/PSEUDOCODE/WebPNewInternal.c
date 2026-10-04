// Function: WebPNewInternal
// RVA: 0x496390, Size: 112 bytes
int64_t WebPNewInternal(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeMalloc(...); // call PLT API at 0x4963c4
    sub_496400(...); // call internal at 0x4963dc
    return a0;
}
