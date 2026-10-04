// Function: __cxa_call_unexpected
// RVA: 0x3aa00, Size: 544 bytes
int64_t __cxa_call_unexpected(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __cxa_begin_catch(...); // call imported API via PLT at 0x3aa28
    _ZSt9terminatev(...); // call imported API via PLT at 0x3aa2c
    __cxa_begin_catch(...); // call imported API via PLT at 0x3aa34
    _ZSt13get_terminatev(...); // call imported API via PLT at 0x3aa5c
    _ZSt14get_unexpectedv(...); // call imported API via PLT at 0x3aa64
    __cxa_begin_catch(...); // call imported API via PLT at 0x3aa74
    __cxa_get_globals_fast(...); // call imported API via PLT at 0x3aad0
    void* g_47010 = (void*)0x47010; // global ref
    _ZNSt13bad_exceptionD1Ev(...); // call imported API via PLT at 0x3ab88
    __cxa_end_catch(...); // call imported API via PLT at 0x3ab8c
    __cxa_end_catch(...); // call imported API via PLT at 0x3ab98
    __cxa_allocate_exception(...); // call imported API via PLT at 0x3aba0
    void* g_47010 = (void*)0x47010; // global ref
    __cxa_throw(...); // call imported API via PLT at 0x3abbc
    __cxa_end_catch(...); // call imported API via PLT at 0x3abdc
    __cxa_end_catch(...); // call imported API via PLT at 0x3abe0
    __cxa_begin_catch(...); // call imported API via PLT at 0x3abe8
    __cxa_rethrow(...); // call imported API via PLT at 0x3abec
    _ZNSt13bad_exceptionD1Ev(...); // call imported API via PLT at 0x3abf8
    __cxa_end_catch(...); // call imported API via PLT at 0x3ac10
}
