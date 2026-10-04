// Function: std::thread::park_timeout_ms::h8cdb6693be460665
// RVA: 0x2f73e4, Size: 224 bytes
int64_t _ZN3std6thread15park_timeout_ms17h8cdb6693be460665E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN3std6thread7current17hedcbf4f61b4b5c7aE(...); // call PLT API at 0x2f73f0
    _ZN3std3sys4unix5futex10futex_wait17h71ecf667fb9977b5E(...); // call PLT API at 0x2f7460
    sub_2E9A60(...); // call internal at 0x2f7498
    return a0;
    sub_2E2300(...); // call internal at 0x2f74ac
    sub_2E243C(...); // call internal at 0x2f74b4
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x2f74bc
}
