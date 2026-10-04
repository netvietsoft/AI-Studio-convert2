// Function: sub_7EA44
// RVA: 0x7ea44, Size: 152 bytes
int64_t sub_7EA44(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    vsnprintf(...); // call imported API via PLT at 0x7eab4
    return a0;
    __stack_chk_fail(...); // call imported API via PLT at 0x7ead8
}
