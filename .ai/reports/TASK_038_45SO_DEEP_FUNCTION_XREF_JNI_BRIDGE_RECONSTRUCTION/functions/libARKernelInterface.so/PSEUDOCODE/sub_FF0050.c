// Function: sub_FF0050
// RVA: 0xff0050, Size: 456 bytes
int64_t sub_FF0050(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_FEF65C(...); // call internal at 0xff01f0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xff0214
}
