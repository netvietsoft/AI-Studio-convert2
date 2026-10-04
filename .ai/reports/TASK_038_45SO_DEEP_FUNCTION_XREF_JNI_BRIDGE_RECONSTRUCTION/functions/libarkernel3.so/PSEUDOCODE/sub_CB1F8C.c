// Function: sub_CB1F8C
// RVA: 0xcb1f8c, Size: 156 bytes
int64_t sub_CB1F8C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    vsnprintf(...); // call PLT API at 0xcb2000
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xcb2024
}
