// Function: sub_CB6934
// RVA: 0xcb6934, Size: 164 bytes
int64_t sub_CB6934(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%s";
    __vsnprintf_chk(...); // call PLT API at 0xcb69b0
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xcb69d4
}
