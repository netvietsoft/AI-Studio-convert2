// Function: std::os::fd::owned::OwnedFd::try_clone::h8f6a839a0e56722e
// RVA: 0x30c198, Size: 116 bytes
int64_t _ZN3std2os2fd5owned7OwnedFd9try_clone17h8f6a839a0e56722eE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fcntl(...); // call PLT API at 0x30c1b4
    return a0;
    __errno(...); // call PLT API at 0x30c1cc
    return a0;
    const char* str = "assertion failed: fd != u32::MAX as RawFdlibrary/std/src/os/fd/owned.rsBorrowedFdOwnedFdlibrary/std/src/panic.rslibrary/std/src/";
    _ZN4core9panicking5panic17haac685927c8c1edbE(...); // call PLT API at 0x30c204
}
