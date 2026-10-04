// Function: sub_FC94D4
// RVA: 0xfc94d4, Size: 164 bytes
int64_t sub_FC94D4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsnprintf_chk(...); // call PLT API at 0xfc9550
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xfc9574
}
