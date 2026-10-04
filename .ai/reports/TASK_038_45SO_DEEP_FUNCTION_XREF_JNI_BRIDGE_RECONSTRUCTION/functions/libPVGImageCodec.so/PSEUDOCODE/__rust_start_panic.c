// Function: __rust_start_panic
// RVA: 0x329cec, Size: 172 bytes
int64_t __rust_start_panic(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...);
    __rust_alloc(...); // call PLT API at 0x329d38
    _ZN5alloc5alloc18handle_alloc_error17hd86fdb6187878245E(...); // call PLT API at 0x329d70
    sub_329B98(...); // call internal at 0x329d80
    sub_4BEBFC(...); // call internal at 0x329d88
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x329d90
}
