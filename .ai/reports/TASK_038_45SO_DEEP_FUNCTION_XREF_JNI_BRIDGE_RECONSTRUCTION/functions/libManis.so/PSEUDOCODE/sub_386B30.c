// Function: sub_386B30
// RVA: 0x386b30, Size: 80 bytes
int64_t sub_386B30(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_386B80(...); // call internal at 0x386b58
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x386b7c
}
