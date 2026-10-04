// Function: SWIG_rt_throw
// RVA: 0x5d1c8, Size: 108 bytes
int64_t SWIG_rt_throw(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0x5d1f4
    strlen(...); // call PLT API at 0x5d204
    malloc(...); // call PLT API at 0x5d20c
    strcpy(...); // call PLT API at 0x5d218
    longjmp(...); // call PLT API at 0x5d230
}
