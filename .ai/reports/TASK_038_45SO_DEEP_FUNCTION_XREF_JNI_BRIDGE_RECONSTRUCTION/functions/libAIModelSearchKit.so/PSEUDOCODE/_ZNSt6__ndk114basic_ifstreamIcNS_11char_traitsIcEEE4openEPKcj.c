// Function: std::__ndk1::basic_ifstream<char, std::__ndk1::char_traits<char>>::open(char const*, unsigned int)
// RVA: 0x976d8, Size: 192 bytes
int64_t _ZNSt6__ndk114basic_ifstreamIcNS_11char_traitsIcEEE4openEPKcj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    _ZNSt6__ndk18ios_base5clearEj(...); // call imported API via PLT at 0x9771c
    fopen(...); // call imported API via PLT at 0x97740
    fseek(...); // call imported API via PLT at 0x9775c
    fclose(...); // call imported API via PLT at 0x97768
    _ZNSt6__ndk18ios_base5clearEj(...); // call imported API via PLT at 0x97794
}
