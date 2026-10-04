// Function: WebPPictureCrop
// RVA: 0x46f210, Size: 824 bytes
int64_t WebPPictureCrop(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_46F11C(...); // call internal at 0x46f274
    sub_46EE00(...); // call internal at 0x46f298
    WebPPictureAlloc(...); // call PLT API at 0x46f2b0
    sub_4526B8(...); // call internal at 0x46f2c4
    WebPCopyPlane(...); // call PLT API at 0x46f350
    WebPCopyPlane(...); // call PLT API at 0x46f388
    WebPCopyPlane(...); // call PLT API at 0x46f3c0
    WebPCopyPlane(...); // call PLT API at 0x46f410
    WebPCopyPlane(...); // call PLT API at 0x46f468
    WebPPictureFree(...); // call PLT API at 0x46f474
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x46f544
}
