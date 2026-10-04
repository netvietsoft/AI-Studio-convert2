// Function: WebPAnimEncoderDelete
// RVA: 0x491a84, Size: 212 bytes
int64_t WebPAnimEncoderDelete(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPPictureFree(...); // call PLT API at 0x491aa8
    WebPPictureFree(...); // call PLT API at 0x491ab4
    WebPPictureFree(...); // call PLT API at 0x491ac0
    sub_491B58(...); // call internal at 0x491b0c
    WebPSafeFree(...); // call PLT API at 0x491b2c
    WebPMuxDelete(...); // call PLT API at 0x491b3c
    WebPSafeFree(...); // call PLT API at 0x491b44
    return a0;
}
