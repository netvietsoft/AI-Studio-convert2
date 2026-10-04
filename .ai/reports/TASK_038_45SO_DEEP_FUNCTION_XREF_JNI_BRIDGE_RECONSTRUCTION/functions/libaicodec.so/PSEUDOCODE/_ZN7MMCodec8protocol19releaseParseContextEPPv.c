// Function: MMCodec::protocol::releaseParseContext(void**)
// RVA: 0x17284c, Size: 88 bytes
int64_t _ZN7MMCodec8protocol19releaseParseContextEPPv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    mm_free_MMH264Context(...); // call imported API via PLT at 0x172878
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x1728a0
}
