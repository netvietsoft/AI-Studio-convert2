// Function: std::__ndk1::basic_filebuf<char, std::__ndk1::char_traits<char>>::open(char const*, unsigned int)
// RVA: 0x97798, Size: 180 bytes
int64_t _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE4openEPKcj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    return a0;
    fopen(...); // call imported API via PLT at 0x977e0
    fseek(...); // call imported API via PLT at 0x97808
    fclose(...); // call imported API via PLT at 0x97814
    return a0;
    return a0;
}
