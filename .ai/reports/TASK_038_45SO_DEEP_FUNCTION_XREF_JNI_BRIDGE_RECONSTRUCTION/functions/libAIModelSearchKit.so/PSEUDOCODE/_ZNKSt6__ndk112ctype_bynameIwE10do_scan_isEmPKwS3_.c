// Function: std::__ndk1::ctype_byname<wchar_t>::do_scan_is(unsigned long, wchar_t const*, wchar_t const*) const
// RVA: 0xbedc8, Size: 304 bytes
int64_t _ZNKSt6__ndk112ctype_bynameIwE10do_scan_isEmPKwS3_(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    iswspace_l(...); // call imported API via PLT at 0xbee18
    iswprint_l(...); // call imported API via PLT at 0xbee2c
    iswcntrl_l(...); // call imported API via PLT at 0xbee40
    iswupper_l(...); // call imported API via PLT at 0xbee54
    iswlower_l(...); // call imported API via PLT at 0xbee68
    iswalpha_l(...); // call imported API via PLT at 0xbee7c
    iswdigit_l(...); // call imported API via PLT at 0xbee90
    iswpunct_l(...); // call imported API via PLT at 0xbeea4
    iswxdigit_l(...); // call imported API via PLT at 0xbeeb8
    iswblank_l(...); // call imported API via PLT at 0xbeecc
    return a0;
}
