// Function: std::sys_common::net::TcpStream::connect::ha20ff0a58da8da7c
// RVA: 0x322c50, Size: 372 bytes
int64_t _ZN3std10sys_common3net9TcpStream7connect17ha20ff0a58da8da7cE(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    socket(...); // call PLT API at 0x322cac
    __errno(...); // call PLT API at 0x322ce8
    return a0;
    connect(...); // call PLT API at 0x322d54
    __errno(...); // call PLT API at 0x322d60
    _ZN3std3sys4unix17decode_error_kind17h9ab9ebcdf23b6a18E(...); // call PLT API at 0x322d6c
    close(...); // call PLT API at 0x322d94
    return a0;
    return a0;
}
