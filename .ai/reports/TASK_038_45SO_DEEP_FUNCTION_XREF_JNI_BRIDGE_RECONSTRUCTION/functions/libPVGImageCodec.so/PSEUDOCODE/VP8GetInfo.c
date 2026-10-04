// Function: VP8GetInfo
// RVA: 0x418d24, Size: 436 bytes
int64_t VP8GetInfo(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    VP8CheckSignature(...); // call PLT API at 0x418d78
    return a0;
}
