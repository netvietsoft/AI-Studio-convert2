// Function: sub_A1F300
// RVA: 0xa1f300, Size: 144 bytes
int64_t sub_A1F300(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memset(...); // call imported API via PLT at 0xa1f340
    sub_A1FD60(...); // call internal func at 0xa1f348
    sub_A26B58(...); // call internal func at 0xa1f358
    sub_A1FE4C(...); // call internal func at 0xa1f360
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0xa1f38c
}
