// Function: sub_A5E80
// RVA: 0xa5e80, Size: 188 bytes
int64_t sub_A5E80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    uselocale(...); // call imported API via PLT at 0xa5ee4
    vsnprintf(...); // call imported API via PLT at 0xa5f04
    uselocale(...); // call imported API via PLT at 0xa5f14
    return a0;
    sub_754CC(...); // call internal func at 0xa5f38
}
