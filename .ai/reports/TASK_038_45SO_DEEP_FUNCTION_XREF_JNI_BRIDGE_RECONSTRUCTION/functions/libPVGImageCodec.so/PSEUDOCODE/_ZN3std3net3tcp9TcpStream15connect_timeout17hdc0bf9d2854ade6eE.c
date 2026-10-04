// Function: std::net::tcp::TcpStream::connect_timeout::hdc0bf9d2854ade6e
// RVA: 0x307d88, Size: 1096 bytes
int64_t _ZN3std3net3tcp9TcpStream15connect_timeout17hdc0bf9d2854ade6eE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    socket(...); // call PLT API at 0x307dcc
    ioctl(...); // call PLT API at 0x307dec
    socket(...); // call PLT API at 0x307e28
    ioctl(...); // call PLT API at 0x307e48
    connect(...); // call PLT API at 0x307e8c
    ioctl(...); // call PLT API at 0x307eac
    __errno(...); // call PLT API at 0x307ebc
    __errno(...); // call PLT API at 0x307ed0
    __errno(...); // call PLT API at 0x307ee4
    ioctl(...); // call PLT API at 0x307f04
    __errno(...); // call PLT API at 0x307f40
    sub_31F7E0(...); // call internal at 0x307f60
    __errno(...); // call PLT API at 0x307f78
    _ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E(...); // call PLT API at 0x307f84
    sub_31F7E0(...); // call internal at 0x307f98
    sub_31F6BC(...); // call internal at 0x307fb8
    _ZN62_$LT$core..time..Duration$u20$as$u20$core..ops..arith..Sub$GT$3sub17h6b477a1d0189f5edE(...); // call PLT API at 0x308008
    poll(...); // call PLT API at 0x308050
    getsockopt(...); // call PLT API at 0x3080a8
    __errno(...); // call PLT API at 0x3080d4
    (*x8)(...);
    __rust_dealloc(...); // call PLT API at 0x308128
    __rust_dealloc(...); // call PLT API at 0x308138
    close(...); // call PLT API at 0x308144
    return a0;
    sub_2E9CDC(...); // call internal at 0x308194
    sub_2E9CE8(...); // call internal at 0x30819c
    sub_2E1774(...); // call internal at 0x3081b0
    sub_2E220C(...); // call internal at 0x3081b8
    sub_4BEBFC(...); // call internal at 0x3081c0
    _ZN4core9panicking15panic_no_unwind17h7efd77c48f29671fE(...); // call PLT API at 0x3081c8
}
