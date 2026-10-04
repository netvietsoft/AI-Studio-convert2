// Function: std::__ndk1::basic_filebuf<char, std::__ndk1::char_traits<char>>::overflow(int)
// RVA: 0x986e4, Size: 532 bytes
int64_t _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE8overflowEi(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fwrite(...); // call imported API via PLT at 0x987f0
    (*x8)(...); // indirect call at 0x98844
    fwrite(...); // call imported API via PLT at 0x98884
    fwrite(...); // call imported API via PLT at 0x988cc
    return a0;
}
