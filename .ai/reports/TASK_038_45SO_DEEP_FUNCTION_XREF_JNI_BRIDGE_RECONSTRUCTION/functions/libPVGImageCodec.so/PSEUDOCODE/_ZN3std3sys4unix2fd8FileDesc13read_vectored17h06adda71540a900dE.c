// Function: std::sys::unix::fd::FileDesc::read_vectored::h06adda71540a900d
// RVA: 0x318a10, Size: 80 bytes
int64_t _ZN3std3sys4unix2fd8FileDesc13read_vectored17h06adda71540a900dE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    readv(...); // call PLT API at 0x318a28
    return a0;
    __errno(...); // call PLT API at 0x318a40
    return a0;
}
