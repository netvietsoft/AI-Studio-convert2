// Function: sub_100C438
// RVA: 0x100c438, Size: 168 bytes
int64_t sub_100C438(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    setjmp(...); // call PLT API at 0x100c484
    sub_100C5B8(...); // call internal at 0x100c4a4
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x100c4dc
}
