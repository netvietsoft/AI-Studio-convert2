// Function: std::sys::unix::kernel_copy::sendfile_splice::h9bf5724cbe3b17c6
// RVA: 0x31b5a0, Size: 528 bytes
int64_t _ZN3std3sys4unix11kernel_copy15sendfile_splice17h9bf5724cbe3b17c6E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    splice(...); // call PLT API at 0x31b61c
    syscall(...); // call PLT API at 0x31b63c
    sendfile(...); // call PLT API at 0x31b68c
    return a0;
    __errno(...); // call PLT API at 0x31b6e4
    sub_2E5054(...); // call internal at 0x31b788
    sub_2E2390(...); // call internal at 0x31b798
    sub_4BEBFC(...); // call internal at 0x31b7a0
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x31b7a8
}
