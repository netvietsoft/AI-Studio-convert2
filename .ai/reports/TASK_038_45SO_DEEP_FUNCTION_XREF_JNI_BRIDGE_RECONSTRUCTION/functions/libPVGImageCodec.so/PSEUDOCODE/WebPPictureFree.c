// Function: WebPPictureFree
// RVA: 0x44f4d4, Size: 76 bytes
int64_t WebPPictureFree(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeFree(...); // call PLT API at 0x44f4f8
    WebPSafeFree(...); // call PLT API at 0x44f504
    sub_44F074(...); // call internal at 0x44f50c
    return a0;
}
