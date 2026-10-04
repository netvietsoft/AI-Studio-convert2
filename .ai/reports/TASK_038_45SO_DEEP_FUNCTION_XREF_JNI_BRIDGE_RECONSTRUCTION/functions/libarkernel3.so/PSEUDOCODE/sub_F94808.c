// Function: sub_F94808
// RVA: 0xf94808, Size: 192 bytes
int64_t sub_F94808(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sincosf(...); // call PLT API at 0xf9483c
    sub_F94EA0(...); // call internal at 0xf94890
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf948c4
}
