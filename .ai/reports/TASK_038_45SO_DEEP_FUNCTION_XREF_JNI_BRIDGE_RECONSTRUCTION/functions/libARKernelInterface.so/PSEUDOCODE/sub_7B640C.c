// Function: sub_7B640C
// RVA: 0x7b640c, Size: 312 bytes
int64_t sub_7B640C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    __vsprintf_chk(...); // call PLT API at 0x7b6488
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x7b64ac
    sub_7B6544(...); // call internal at 0x7b64dc
    (*x8)(...);
    _ZdlPv(...); // call PLT API at 0x7b6500
    (*x8)(...);
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x7b6540
}
