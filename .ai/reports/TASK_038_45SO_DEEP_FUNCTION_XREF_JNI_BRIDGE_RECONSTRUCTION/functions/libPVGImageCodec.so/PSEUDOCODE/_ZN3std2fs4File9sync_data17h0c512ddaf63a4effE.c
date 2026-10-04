// Function: std::fs::File::sync_data::h0c512ddaf63a4eff
// RVA: 0x2fb928, Size: 108 bytes
int64_t _ZN3std2fs4File9sync_data17h0c512ddaf63a4effE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fdatasync(...); // call PLT API at 0x2fb938
    return a0;
    fdatasync(...); // call PLT API at 0x2fb958
    __errno(...); // call PLT API at 0x2fb964
    _ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E(...); // call PLT API at 0x2fb970
    return a0;
}
