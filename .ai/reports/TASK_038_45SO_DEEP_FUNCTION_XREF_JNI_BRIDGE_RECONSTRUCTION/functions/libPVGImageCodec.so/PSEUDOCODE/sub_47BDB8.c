// Function: sub_47BDB8
// RVA: 0x47bdb8, Size: 300 bytes
int64_t sub_47BDB8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    WebPSafeMalloc(...); // call PLT API at 0x47be1c
    sub_47BEE4(...); // call internal at 0x47be50
    sub_47C49C(...); // call internal at 0x47be70
    sub_47C564(...); // call internal at 0x47be8c
    WebPSafeFree(...); // call PLT API at 0x47beac
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x47bee0
}
