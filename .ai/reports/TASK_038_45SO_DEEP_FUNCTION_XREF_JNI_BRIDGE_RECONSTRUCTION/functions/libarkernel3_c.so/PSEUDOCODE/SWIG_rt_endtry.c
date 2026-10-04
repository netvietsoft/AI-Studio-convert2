// Function: SWIG_rt_endtry
// RVA: 0x5d26c, Size: 120 bytes
int64_t SWIG_rt_endtry(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    setjmp(...); // call PLT API at 0x5d28c
    sub_5D0B0(...); // call internal at 0x5d294
    longjmp(...); // call PLT API at 0x5d2a4
    memcpy(...); // call PLT API at 0x5d2d8
    return a0;
}
