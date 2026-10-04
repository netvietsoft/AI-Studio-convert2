// Function: utils::PathUtils::executablePath(unsigned int)
// RVA: 0x7947c, Size: 648 bytes
int64_t _ZN5utils9PathUtils14executablePathEj(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* s_493a5 = "/proc/self/exe";
    readlink(...); // call imported API via PLT at 0x794cc
    _ZdlPv(...); // call imported API via PLT at 0x79510
    _ZNKSt6__ndk112basic_stringIcNS_11char_traitsIcEENS_9allocatorIcEEE5rfindEcm(...); // call imported API via PLT at 0x79560
    _Znwm(...); // call imported API via PLT at 0x795c8
    memmove(...); // call imported API via PLT at 0x795e8
    _ZdlPv(...); // call imported API via PLT at 0x795fc
    return a0;
    _ZdlPv(...); // call imported API via PLT at 0x7965c
    _Znwm(...); // call imported API via PLT at 0x7966c
    memcpy(...); // call imported API via PLT at 0x7968c
    sub_754DC(...); // call internal func at 0x796b4
    sub_754DC(...); // call internal func at 0x796cc
    _ZdlPv(...); // call imported API via PLT at 0x796e4
    __stack_chk_fail(...); // call imported API via PLT at 0x79700
}
