// Function: sub_D35AA8
// RVA: 0xd35aa8, Size: 228 bytes
int64_t sub_D35AA8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sub_B79DC8(...); // call internal at 0xd35ac8
    const char* str = "FILE*";
    sub_B7A8D0(...); // call internal at 0xd35ae0
    fopen(...); // call PLT API at 0xd35af8
    return a0;
    __errno(...); // call PLT API at 0xd35b14
    strerror(...); // call PLT API at 0xd35b1c
    const char* str = "cannot open file '%s' (%s)";
    sub_B7A51C(...); // call internal at 0xd35b40
    const char* str = "FILE*";
    sub_B7A990(...); // call internal at 0xd35b60
    fclose(...); // call PLT API at 0xd35b68
    sub_B7A730(...); // call internal at 0xd35b88
}
