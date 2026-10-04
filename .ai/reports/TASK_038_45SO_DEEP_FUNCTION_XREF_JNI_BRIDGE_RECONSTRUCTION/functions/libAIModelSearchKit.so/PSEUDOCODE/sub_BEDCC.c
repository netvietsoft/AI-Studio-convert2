// Function: sub_BEDCC
// RVA: 0xbedcc, Size: 300 bytes
int64_t sub_BEDCC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
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
