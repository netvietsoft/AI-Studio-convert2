// Function: std::__ndk1::basic_string<wchar_t, std::__ndk1::char_traits<wchar_t>, std::__ndk1::allocator<wchar_t>>::append(wchar_t const*)
// RVA: 0x86478, Size: 232 bytes
int64_t _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE6appendEPKw(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    wcslen(...); // call imported API via PLT at 0x8649c
    _ZNSt6__ndk112basic_stringIwNS_11char_traitsIwEENS_9allocatorIwEEE21__grow_by_and_replaceEmmmmmmPKw(...); // call imported API via PLT at 0x864f8
    memmove(...); // call imported API via PLT at 0x86520
    return a0;
}
