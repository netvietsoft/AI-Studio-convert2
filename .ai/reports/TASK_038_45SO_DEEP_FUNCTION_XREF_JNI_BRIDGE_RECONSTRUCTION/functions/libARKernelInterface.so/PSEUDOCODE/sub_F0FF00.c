// Function: sub_F0FF00
// RVA: 0xf0ff00, Size: 120 bytes
int64_t sub_F0FF00(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    strlen(...); // call PLT API at 0xf0ff2c
    sub_F0E1C4(...); // call internal at 0xf0ff4c
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xf0ff74
}
