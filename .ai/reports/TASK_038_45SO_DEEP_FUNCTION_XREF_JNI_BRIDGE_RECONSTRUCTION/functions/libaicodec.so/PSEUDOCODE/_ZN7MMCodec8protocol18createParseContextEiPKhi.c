// Function: MMCodec::protocol::createParseContext(int, unsigned char const*, int)
// RVA: 0x1727a0, Size: 172 bytes
int64_t _ZN7MMCodec8protocol18createParseContextEiPKhi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    mm_alloc_MMH264ExtraContext(...); // call imported API via PLT at 0x1727cc
    mm_h264_decode_extradata(...); // call imported API via PLT at 0x1727ec
    mm_free_MMH264ExtraContext(...); // call imported API via PLT at 0x1727f8
    mm_alloc_MMH264Context(...); // call imported API via PLT at 0x172800
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x172848
}
