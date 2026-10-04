// Function: std::os::unix::net::listener::UnixListener::bind_addr::h41c73f863a989601
// RVA: 0x30aa08, Size: 204 bytes
int64_t _ZN3std2os4unix3net8listener12UnixListener9bind_addr17h41c73f863a989601E(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    socket(...); // call PLT API at 0x30aa30
    bind(...); // call PLT API at 0x30aa48
    listen(...); // call PLT API at 0x30aa5c
    return a0;
    __errno(...); // call PLT API at 0x30aa7c
    return a0;
    __errno(...); // call PLT API at 0x30aaa4
    close(...); // call PLT API at 0x30aad0
}
