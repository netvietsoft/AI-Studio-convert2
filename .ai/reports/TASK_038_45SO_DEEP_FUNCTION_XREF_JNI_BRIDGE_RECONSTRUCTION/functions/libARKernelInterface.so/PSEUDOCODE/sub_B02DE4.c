// Function: sub_B02DE4
// RVA: 0xb02de4, Size: 164 bytes
int64_t sub_B02DE4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%d";
    __vsprintf_chk(...); // call PLT API at 0xb02e60
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xb02e84
}
