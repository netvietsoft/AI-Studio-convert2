// Function: mizar::NpuAdapterImpl::IsSupport()
// RVA: 0xdb110, Size: 1168 bytes
int64_t _ZN5mizar14NpuAdapterImpl9IsSupportEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "ro.product.vendor.device";
    __system_property_get(...); // call PLT API at 0xdb160
    strlen(...); // call PLT API at 0xdb170
    _Znwm(...); // call PLT API at 0xdb1b0
    memcpy(...); // call PLT API at 0xdb1d0
    const char* str = "orIS3_EEEE";
    sub_DB5A0(...); // call internal at 0xdb3b4
    _ZdlPv(...); // call PLT API at 0xdb3c4
    memchr(...); // call PLT API at 0xdb448
    memcmp(...); // call PLT API at 0xdb45c
    _ZdlPv(...); // call PLT API at 0xdb4d8
    _ZdlPv(...); // call PLT API at 0xdb4e8
    _ZdlPv(...); // call PLT API at 0xdb4f8
    return a0;
    sub_72540(...); // call internal at 0xdb544
    sub_EB464(...); // call internal at 0xdb570
    _ZdlPv(...); // call PLT API at 0xdb578
    _ZdlPv(...); // call PLT API at 0xdb588
    __stack_chk_fail(...); // call PLT API at 0xdb59c
}
