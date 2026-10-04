// Function: sub_CCB64C
// RVA: 0xccb64c, Size: 312 bytes
int64_t sub_CCB64C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsnprintf_chk(...); // call imported API via PLT at 0xccb6e0
    _ZNSt6__ndk15mutex4lockEv(...); // call imported API via PLT at 0xccb6f0
    sub_CCB784(...); // call internal func at 0xccb704
    __vsnprintf_chk(...); // call imported API via PLT at 0xccb720
    _ZNSt6__ndk15mutex6unlockEv(...); // call imported API via PLT at 0xccb748
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xccb77c
    sub_562D14(...); // call internal func at 0xccb780
}
