// Function: _$LT$std..sys..unix..fs..Dir$u20$as$u20$core..ops..drop..Drop$GT$::drop::h7981615b659d0cbc
// RVA: 0x3190fc, Size: 176 bytes
int64_t _ZN65_$LT$std..sys..unix..fs..Dir$u20$as$u20$core..ops..drop..Drop$GT$4drop17h7981615b659d0cbcE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    closedir(...); // call PLT API at 0x319108
    __errno(...); // call PLT API at 0x319110
    _ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E(...); // call PLT API at 0x319118
    return a0;
    __errno(...); // call PLT API at 0x319134
    _ZN4core9panicking9panic_fmt17h86163c13bfcb8e07E(...); // call PLT API at 0x319184
    sub_2E2390(...); // call internal at 0x319194
    sub_4BEBFC(...); // call internal at 0x31919c
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x3191a4
}
