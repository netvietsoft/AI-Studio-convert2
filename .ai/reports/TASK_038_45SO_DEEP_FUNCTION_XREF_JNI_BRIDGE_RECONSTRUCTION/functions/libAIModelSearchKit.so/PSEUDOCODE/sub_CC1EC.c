// Function: sub_CC1EC
// RVA: 0xcc1ec, Size: 96 bytes
int64_t sub_CC1EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    uselocale(...); // call imported API via PLT at 0xcc1fc
    return a0;
    sub_754CC(...); // call internal func at 0xcc20c
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0xcc23c
    return a0;
}
