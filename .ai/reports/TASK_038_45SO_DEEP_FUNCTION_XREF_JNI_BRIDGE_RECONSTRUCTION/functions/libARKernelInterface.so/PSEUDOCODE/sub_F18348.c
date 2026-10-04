// Function: sub_F18348
// RVA: 0xf18348, Size: 228 bytes
int64_t sub_F18348(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_F0E5B8(...); // call internal at 0xf18368
    const char* str = "FILE*";
    sub_F0F0C0(...); // call internal at 0xf18380
    fopen(...); // call PLT API at 0xf18398
    return a0;
    __errno(...); // call PLT API at 0xf183b4
    strerror(...); // call PLT API at 0xf183bc
    const char* str = "cannot open file '%s' (%s)";
    sub_F0ED0C(...); // call internal at 0xf183e0
    const char* str = "FILE*";
    sub_F0F180(...); // call internal at 0xf18400
    fclose(...); // call PLT API at 0xf18408
    sub_F0EF20(...); // call internal at 0xf18428
}
