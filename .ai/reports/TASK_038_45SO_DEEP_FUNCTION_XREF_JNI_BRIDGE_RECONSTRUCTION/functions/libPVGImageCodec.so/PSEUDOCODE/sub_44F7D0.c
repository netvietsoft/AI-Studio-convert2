// Function: sub_44F7D0
// RVA: 0x44f7d0, Size: 428 bytes
int64_t sub_44F7D0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_44FBE4(...); // call internal at 0x44f838
    sub_44FC1C(...); // call internal at 0x44f848
    WebPMemoryWriterInit(...); // call PLT API at 0x44f8a8
    (*x8)(...);
    WebPEncode(...); // call PLT API at 0x44f8d8
    WebPPictureFree(...); // call PLT API at 0x44f8fc
    WebPMemoryWriterClear(...); // call PLT API at 0x44f910
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x44f978
}
