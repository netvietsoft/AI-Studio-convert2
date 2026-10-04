// Function: WebPAnimEncoderNewInternal
// RVA: 0x491470, Size: 720 bytes
int64_t WebPAnimEncoderNewInternal(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeCalloc(...); // call PLT API at 0x4914f4
    sub_491740(...); // call internal at 0x491514
    memcpy(...); // call PLT API at 0x49154c
    sub_491758(...); // call internal at 0x491558
    sub_491420(...); // call internal at 0x491568
    sub_491988(...); // call internal at 0x491578
    sub_491988(...); // call internal at 0x49158c
    sub_491988(...); // call internal at 0x4915a0
    WebPPictureAlloc(...); // call PLT API at 0x4915dc
    WebPPictureCopy(...); // call PLT API at 0x4915f8
    WebPPictureCopy(...); // call PLT API at 0x491614
    sub_4919B0(...); // call internal at 0x491630
    sub_491A2C(...); // call internal at 0x491644
    WebPSafeCalloc(...); // call PLT API at 0x4916a0
    sub_491A6C(...); // call internal at 0x4916c0
    WebPAnimEncoderDelete(...); // call PLT API at 0x491724
    return a0;
}
