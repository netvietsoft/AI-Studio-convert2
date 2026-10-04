// Function: sub_BEEFC
// RVA: 0xbeefc, Size: 300 bytes
int64_t sub_BEEFC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    iswspace_l(...); // call imported API via PLT at 0xbef34
    iswprint_l(...); // call imported API via PLT at 0xbef5c
    iswcntrl_l(...); // call imported API via PLT at 0xbef70
    iswupper_l(...); // call imported API via PLT at 0xbef84
    iswlower_l(...); // call imported API via PLT at 0xbef98
    iswalpha_l(...); // call imported API via PLT at 0xbefac
    iswdigit_l(...); // call imported API via PLT at 0xbefc0
    iswpunct_l(...); // call imported API via PLT at 0xbefd4
    iswxdigit_l(...); // call imported API via PLT at 0xbefe8
    iswblank_l(...); // call imported API via PLT at 0xbeffc
    return a0;
}
