// Function: SWIG_rt_unhandled
// RVA: 0x5d234, Size: 56 bytes
int64_t SWIG_rt_unhandled(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    free(...); // call PLT API at 0x5d250
    sub_5D194(...); // call internal at 0x5d258
    longjmp(...); // call PLT API at 0x5d268
}
