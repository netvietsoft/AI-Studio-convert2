// Function: std::fs::File::sync_all::h73f00dda1044c0a7
// RVA: 0x2fb8bc, Size: 108 bytes
int64_t _ZN3std2fs4File8sync_all17h73f00dda1044c0a7E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fsync(...); // call PLT API at 0x2fb8cc
    return a0;
    fsync(...); // call PLT API at 0x2fb8ec
    __errno(...); // call PLT API at 0x2fb8f8
    _ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E(...); // call PLT API at 0x2fb904
    return a0;
}
