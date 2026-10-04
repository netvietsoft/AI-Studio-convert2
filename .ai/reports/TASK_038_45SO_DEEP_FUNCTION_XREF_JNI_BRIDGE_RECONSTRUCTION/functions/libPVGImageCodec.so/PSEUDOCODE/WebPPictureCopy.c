// Function: WebPPictureCopy
// RVA: 0x46ec0c, Size: 500 bytes
int64_t WebPPictureCopy(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_46EE00(...); // call internal at 0x46ec68
    WebPPictureAlloc(...); // call PLT API at 0x46ec70
    WebPCopyPlane(...); // call PLT API at 0x46ecc4
    WebPCopyPlane(...); // call PLT API at 0x46ed08
    WebPCopyPlane(...); // call PLT API at 0x46ed4c
    WebPCopyPlane(...); // call PLT API at 0x46ed90
    WebPCopyPlane(...); // call PLT API at 0x46eddc
    return a0;
}
