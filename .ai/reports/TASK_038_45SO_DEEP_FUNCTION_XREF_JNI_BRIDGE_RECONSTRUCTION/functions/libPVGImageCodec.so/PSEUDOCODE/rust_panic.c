// Function: rust_panic
// RVA: 0x3164d4, Size: 136 bytes
int64_t rust_panic(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __rust_start_panic(...); // call PLT API at 0x3164e4
    sub_3046E4(...); // call internal at 0x31654c
    sub_2E3198(...); // call internal at 0x316550
    _ZN3std3sys4unix14abort_internal17h0da7964cfecd09ddE(...); // call PLT API at 0x316554
}
