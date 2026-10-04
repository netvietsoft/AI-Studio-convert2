// Function: sub_963B04
// RVA: 0x963b04, Size: 256 bytes
int64_t sub_963B04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    memcpy(...); // call PLT API at 0x963b68
    sub_963C04(...); // call internal at 0x963bcc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x963c00
}
