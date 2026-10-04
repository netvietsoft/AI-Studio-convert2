// Function: sub_FE47A8
// RVA: 0xfe47a8, Size: 984 bytes
int64_t sub_FE47A8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0xfe48b4
    sincosf(...); // call PLT API at 0xfe48d0
    sub_FCA700(...); // call internal at 0xfe493c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfe4b7c
}
