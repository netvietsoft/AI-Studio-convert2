// Function: MMCodec::MediaFilter::~MediaFilter()
// RVA: 0x15a240, Size: 292 bytes
int64_t _ZN7MMCodec11MediaFilterD1Ev(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    mm_free_MMH264ExtraContext(...); // call imported API via PLT at 0x15a28c
    return a0;
    mm_free_MMH264Context(...); // call imported API via PLT at 0x15a308
    __stack_chk_fail(...); // call imported API via PLT at 0x15a358
    sub_CEBC4(...); // call internal func at 0x15a35c
    sub_CEBC4(...); // call internal func at 0x15a360
}
