// Function: sub_8C100
// RVA: 0x8c100, Size: 52 bytes
int64_t sub_8C100(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_allocate_exception(...); // call imported API via PLT at 0x8c110
    _ZNSt9bad_allocC1Ev(...); // call imported API via PLT at 0x8c118
    __cxa_throw(...); // call imported API via PLT at 0x8c130
}
