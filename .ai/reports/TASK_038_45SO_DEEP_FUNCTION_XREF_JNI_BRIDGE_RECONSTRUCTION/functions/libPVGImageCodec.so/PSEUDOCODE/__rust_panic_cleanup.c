// Function: __rust_panic_cleanup
// RVA: 0x329c84, Size: 104 bytes
int64_t __rust_panic_cleanup(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __rust_dealloc(...); // call PLT API at 0x329cc8
    return a0;
    sub_4BEDDC(...); // call internal at 0x329ce0
    __rust_foreign_exception(...); // call PLT API at 0x329ce4
}
