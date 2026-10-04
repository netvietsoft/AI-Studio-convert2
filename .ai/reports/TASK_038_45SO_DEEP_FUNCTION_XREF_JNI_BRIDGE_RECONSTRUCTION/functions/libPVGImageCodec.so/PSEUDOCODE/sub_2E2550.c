// Function: sub_2E2550
// RVA: 0x2e2550, Size: 208 bytes
int64_t sub_2E2550(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    syscall(...); // call PLT API at 0x2e2588
    return a0;
    __rust_dealloc(...); // call PLT API at 0x2e25e8
    __rust_dealloc(...); // call PLT API at 0x2e2610
    return a0;
}
