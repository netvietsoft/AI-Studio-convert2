// Function: sub_DA7F80
// RVA: 0xda7f80, Size: 640 bytes
int64_t sub_DA7F80(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x8)(...); // indirect call at 0xda80e8
    sub_DA833C(...); // call internal func at 0xda814c
    (*x8)(...); // indirect call at 0xda817c
    sub_DA7760(...); // call internal func at 0xda8198
    return a0;
    sub_DA7760(...); // call internal func at 0xda81dc
    __stack_chk_fail(...); // call imported API via PLT at 0xda81f8
    return a0;
}
