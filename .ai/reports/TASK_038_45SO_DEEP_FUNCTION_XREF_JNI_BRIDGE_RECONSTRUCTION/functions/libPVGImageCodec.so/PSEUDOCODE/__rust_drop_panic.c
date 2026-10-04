// Function: __rust_drop_panic
// RVA: 0x314f30, Size: 228 bytes
int64_t __rust_drop_panic(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "/rustc/d5a82bbd26e1ad8b7401f6a718a9c57c96905483/library/core/src/slice/iter.rs()/rustc/d5a82bbd26e1ad8b7401f6a718a9c57c96905483/";
    sub_3046E4(...); // call internal at 0x314f90
    (*x8)(...);
    __rust_dealloc(...); // call PLT API at 0x314fd0
    __rust_dealloc(...); // call PLT API at 0x314fe0
    _ZN3std3sys4unix14abort_internal17h0da7964cfecd09ddE(...); // call PLT API at 0x314fe4
    sub_2E9CDC(...); // call internal at 0x314ff8
    sub_2E9CE8(...); // call internal at 0x315000
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x315004
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x31500c
}
