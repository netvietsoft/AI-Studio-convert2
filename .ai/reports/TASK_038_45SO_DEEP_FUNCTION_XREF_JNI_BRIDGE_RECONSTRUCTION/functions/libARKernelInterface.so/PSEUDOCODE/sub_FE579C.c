// Function: sub_FE579C
// RVA: 0xfe579c, Size: 852 bytes
int64_t sub_FE579C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0xfe58d8
    sincosf(...); // call PLT API at 0xfe58f0
    sub_FE556C(...); // call internal at 0xfe5954
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfe5aec
}
