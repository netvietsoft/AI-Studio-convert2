// Function: std::__ndk1::basic_filebuf<char, std::__ndk1::char_traits<char>>::close()
// RVA: 0x97e40, Size: 140 bytes
int64_t _ZNSt6__ndk113basic_filebufIcNS_11char_traitsIcEEE5closeEv(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0x97e68
    fclose(...); // call imported API via PLT at 0x97e74
    (*x8)(...); // indirect call at 0x97e9c
    return a0;
    fclose(...); // call imported API via PLT at 0x97ec0
}
