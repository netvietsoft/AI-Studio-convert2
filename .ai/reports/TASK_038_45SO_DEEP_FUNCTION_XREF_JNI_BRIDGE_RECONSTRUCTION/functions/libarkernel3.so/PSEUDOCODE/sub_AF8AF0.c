// Function: sub_AF8AF0
// RVA: 0xaf8af0, Size: 112 bytes
int64_t sub_AF8AF0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memset(...); // call imported API via PLT at 0xaf8b28
    sub_AF8C28(...); // call internal func at 0xaf8b30
    return a0;
}
