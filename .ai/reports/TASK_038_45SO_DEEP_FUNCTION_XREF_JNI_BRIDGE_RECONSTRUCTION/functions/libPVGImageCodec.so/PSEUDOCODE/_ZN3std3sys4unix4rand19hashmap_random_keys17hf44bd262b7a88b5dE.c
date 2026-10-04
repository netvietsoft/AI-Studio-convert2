// Function: std::sys::unix::rand::hashmap_random_keys::hf44bd262b7a88b5d
// RVA: 0x31e2f4, Size: 836 bytes
int64_t _ZN3std3sys4unix4rand19hashmap_random_keys17hf44bd262b7a88b5dE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    getrandom(...); // call PLT API at 0x31e34c
    getrandom(...); // call PLT API at 0x31e374
    syscall(...); // call PLT API at 0x31e394
    __errno(...); // call PLT API at 0x31e3a0
    syscall(...); // call PLT API at 0x31e3c8
    __errno(...); // call PLT API at 0x31e3d4
    const char* str = "/dev/urandomfailed to open /dev/urandomfailed to read /dev/urandomlibrary/std/src/sys/unix/thread.rsfailed to join thread: The n";
    _ZN4core3ffi5c_str4CStr19from_bytes_with_nul17h82c31c91b2dddbffE(...); // call PLT API at 0x31e464
    sub_3191AC(...); // call internal at 0x31e47c
    __errno(...); // call PLT API at 0x31e49c
    _ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E(...); // call PLT API at 0x31e4a8
    read(...); // call PLT API at 0x31e4cc
    close(...); // call PLT API at 0x31e4f4
    return a0;
    _ZN4core5slice5index26slice_start_index_len_fail17hd5d9e7bbf6d4ec6dE(...); // call PLT API at 0x31e530
    const char* str = "failed to read /dev/urandomlibrary/std/src/sys/unix/thread.rsfailed to join thread: The number of hardware threads is not known ";
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E(...); // call PLT API at 0x31e564
    _ZN4core9panicking9panic_fmt17h86163c13bfcb8e07E(...); // call PLT API at 0x31e5a4
    const char* str = "failed to open /dev/urandomfailed to read /dev/urandomlibrary/std/src/sys/unix/thread.rsfailed to join thread: The number of har";
    _ZN4core6result13unwrap_failed17h991d2f44e0c0e2b1E(...); // call PLT API at 0x31e5e8
    sub_2E2390(...); // call internal at 0x31e5f8
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x31e600
    sub_2E2390(...); // call internal at 0x31e618
    sub_2E220C(...); // call internal at 0x31e620
    sub_4BEBFC(...); // call internal at 0x31e628
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x31e630
}
