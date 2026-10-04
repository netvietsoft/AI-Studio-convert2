// Function: sub_B8D500
// RVA: 0xb8d500, Size: 1024 bytes
int64_t sub_B8D500(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memset(...); // call imported API via PLT at 0xb8d54c
    sub_B8DA00(...); // call internal func at 0xb8d744
    sub_B8DA00(...); // call internal func at 0xb8d768
    sub_B8DBF4(...); // call internal func at 0xb8d778
    sub_B8DA00(...); // call internal func at 0xb8d7f0
    sub_B8DA00(...); // call internal func at 0xb8d814
    sub_B8DBF4(...); // call internal func at 0xb8d824
    free(...); // call imported API via PLT at 0xb8d860
    free(...); // call imported API via PLT at 0xb8d870
    free(...); // call imported API via PLT at 0xb8d880
    return a0;
    free(...); // call imported API via PLT at 0xb8d8c4
    free(...); // call imported API via PLT at 0xb8d8e0
    __stack_chk_fail(...); // call imported API via PLT at 0xb8d8fc
}
