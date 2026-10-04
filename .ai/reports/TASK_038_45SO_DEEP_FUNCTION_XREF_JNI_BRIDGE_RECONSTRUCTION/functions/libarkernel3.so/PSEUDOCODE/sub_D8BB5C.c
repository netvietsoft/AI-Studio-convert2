// Function: sub_D8BB5C
// RVA: 0xd8bb5c, Size: 96 bytes
int64_t sub_D8BB5C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_D8BBBC(...); // call internal at 0xd8bb80
    _ZdlPv(...); // call PLT API at 0xd8bb90
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xd8bbb8
}
