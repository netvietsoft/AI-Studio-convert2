// Function: sub_E0FDF0
// RVA: 0xe0fdf0, Size: 200 bytes
int64_t sub_E0FDF0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    (*x9)(...);
    vfprintf(...); // call PLT API at 0xe0fe90
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe0feb4
}
