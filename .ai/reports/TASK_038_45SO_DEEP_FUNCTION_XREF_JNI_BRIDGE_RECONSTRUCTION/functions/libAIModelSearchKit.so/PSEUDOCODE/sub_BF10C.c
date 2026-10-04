// Function: sub_BF10C
// RVA: 0xbf10c, Size: 108 bytes
int64_t sub_BF10C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    uselocale(...); // call imported API via PLT at 0xbf124
    btowc(...); // call imported API via PLT at 0xbf134
    uselocale(...); // call imported API via PLT at 0xbf144
    return a0;
    sub_754CC(...); // call internal func at 0xbf160
}
