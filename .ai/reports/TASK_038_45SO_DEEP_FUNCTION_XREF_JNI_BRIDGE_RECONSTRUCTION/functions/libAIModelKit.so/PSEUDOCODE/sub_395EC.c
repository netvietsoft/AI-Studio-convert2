// Function: sub_395EC
// RVA: 0x395ec, Size: 144 bytes
int64_t sub_395EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    posix_memalign(...); // call imported API via PLT at 0x39620
    _ZSt15get_new_handlerv(...); // call imported API via PLT at 0x3962c
    (*x0)(...); // indirect call at 0x39634
    return a0;
    __cxa_allocate_exception(...); // call imported API via PLT at 0x39654
    _ZNSt9bad_allocC1Ev(...); // call imported API via PLT at 0x3965c
    __cxa_throw(...); // call imported API via PLT at 0x39674
}
