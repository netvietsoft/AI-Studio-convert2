// Function: sub_EDC00
// RVA: 0xedc00, Size: 164 bytes
int64_t sub_EDC00(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsprintf_chk(...); // call PLT API at 0xedc7c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xedca0
}
