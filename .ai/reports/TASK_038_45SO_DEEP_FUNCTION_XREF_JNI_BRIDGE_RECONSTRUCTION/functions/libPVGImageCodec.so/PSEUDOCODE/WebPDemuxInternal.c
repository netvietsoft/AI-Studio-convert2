// Function: WebPDemuxInternal
// RVA: 0x48e7e0, Size: 888 bytes
int64_t WebPDemuxInternal(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_48EB58(...); // call internal at 0x48e894
    sub_48EBBC(...); // call internal at 0x48e8b0
    sub_48ED00(...); // call internal at 0x48e8dc
    WebPSafeCalloc(...); // call PLT API at 0x48e994
    sub_48EF08(...); // call internal at 0x48e9bc
    const char* str = "VP8 ";
    sub_48EF88(...); // call internal at 0x48e9f4
    (*x8)(...);
    (*x8)(...);
    WebPDemuxDelete(...); // call PLT API at 0x48eb08
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x48eb54
}
