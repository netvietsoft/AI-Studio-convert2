// Function: std::thread::park_timeout::ha7da7e454f267fae
// RVA: 0x2f74c4, Size: 180 bytes
int64_t _ZN3std6thread12park_timeout17ha7da7e454f267faeE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZN3std6thread7current17hedcbf4f61b4b5c7aE(...); // call PLT API at 0x2f74d8
    _ZN3std3sys4unix5futex10futex_wait17h71ecf667fb9977b5E(...); // call PLT API at 0x2f750c
    sub_2E9A60(...); // call internal at 0x2f7548
    return a0;
    sub_2E2300(...); // call internal at 0x2f7560
    sub_2E243C(...); // call internal at 0x2f7568
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x2f7570
}
