// Function: sub_E19FA0
// RVA: 0xe19fa0, Size: 96 bytes
int64_t sub_E19FA0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_E1A000(...); // call internal at 0xe19fc4
    _ZdlPv(...); // call PLT API at 0xe19fd4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xe19ffc
}
