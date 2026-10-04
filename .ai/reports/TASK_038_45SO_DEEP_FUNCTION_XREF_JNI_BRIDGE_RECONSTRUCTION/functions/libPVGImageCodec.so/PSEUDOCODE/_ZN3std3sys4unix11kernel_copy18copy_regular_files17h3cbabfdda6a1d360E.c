// Function: std::sys::unix::kernel_copy::copy_regular_files::h3cbabfdda6a1d360
// RVA: 0x31b3cc, Size: 468 bytes
int64_t _ZN3std3sys4unix11kernel_copy18copy_regular_files17h3cbabfdda6a1d360E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    copy_file_range(...); // call PLT API at 0x31b42c
    syscall(...); // call PLT API at 0x31b458
    __errno(...); // call PLT API at 0x31b464
    copy_file_range(...); // call PLT API at 0x31b4b8
    syscall(...); // call PLT API at 0x31b4dc
    return a0;
    return a0;
    __errno(...); // call PLT API at 0x31b540
}
