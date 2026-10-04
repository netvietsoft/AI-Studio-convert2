// Function: std::__ndk1::ctype_byname<wchar_t>::do_is(wchar_t const*, wchar_t const*, unsigned long*) const
// RVA: 0xbec2c, Size: 412 bytes
int64_t _ZNKSt6__ndk112ctype_bynameIwE5do_isEPKwS3_Pm(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    iswspace_l(...); // call imported API via PLT at 0xbec98
    iswprint_l(...); // call imported API via PLT at 0xbecb4
    iswcntrl_l(...); // call imported API via PLT at 0xbecd0
    iswupper_l(...); // call imported API via PLT at 0xbecec
    iswlower_l(...); // call imported API via PLT at 0xbed08
    iswalpha_l(...); // call imported API via PLT at 0xbed24
    iswdigit_l(...); // call imported API via PLT at 0xbed40
    iswpunct_l(...); // call imported API via PLT at 0xbed5c
    iswxdigit_l(...); // call imported API via PLT at 0xbed78
    iswblank_l(...); // call imported API via PLT at 0xbed94
    return a0;
}
