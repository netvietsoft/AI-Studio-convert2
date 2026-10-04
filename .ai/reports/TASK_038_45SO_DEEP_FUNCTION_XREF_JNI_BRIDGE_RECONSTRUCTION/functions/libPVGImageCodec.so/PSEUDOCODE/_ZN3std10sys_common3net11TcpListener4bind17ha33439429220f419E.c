// Function: std::sys_common::net::TcpListener::bind::ha33439429220f419
// RVA: 0x323108, Size: 436 bytes
int64_t _ZN3std10sys_common3net11TcpListener4bind17ha33439429220f419E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    socket(...); // call PLT API at 0x323164
    setsockopt(...); // call PLT API at 0x323190
    __errno(...); // call PLT API at 0x3231c8
    return a0;
    __errno(...); // call PLT API at 0x3231f8
    bind(...); // call PLT API at 0x32324c
    listen(...); // call PLT API at 0x323260
    return a0;
    __errno(...); // call PLT API at 0x323284
    close(...); // call PLT API at 0x3232a4
    return a0;
}
