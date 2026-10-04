// Function: WebPPictureAlloc
// RVA: 0x44f464, Size: 112 bytes
int64_t WebPPictureAlloc(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPPictureFree(...); // call PLT API at 0x44f484
    sub_44F1F8(...); // call internal at 0x44f49c
    sub_44F118(...); // call internal at 0x44f4ac
    return a0;
}
