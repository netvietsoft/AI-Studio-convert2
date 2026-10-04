// Function: sub_F9D050
// RVA: 0xf9d050, Size: 280 bytes
int64_t sub_F9D050(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_F9D168(...); // call internal at 0xf9d0ac
    memmove(...); // call PLT API at 0xf9d0dc
    memmove(...); // call PLT API at 0xf9d124
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf9d164
}
