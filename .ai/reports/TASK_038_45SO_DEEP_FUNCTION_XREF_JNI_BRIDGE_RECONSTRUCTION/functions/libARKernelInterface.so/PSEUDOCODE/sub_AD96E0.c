// Function: sub_AD96E0
// RVA: 0xad96e0, Size: 540 bytes
int64_t sub_AD96E0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    glViewport(...); // call PLT API at 0xad971c
    glUseProgram(...); // call PLT API at 0xad9724
    glActiveTexture(...); // call PLT API at 0xad972c
    glBindTexture(...); // call PLT API at 0xad9738
    const char* str = "srcMap";
    sub_AD94A4(...); // call internal at 0xad974c
    glActiveTexture(...); // call PLT API at 0xad9768
    glBindTexture(...); // call PLT API at 0xad9778
    const char* str = "additionalMap";
    sub_AD94A4(...); // call internal at 0xad978c
    sub_FC2A84(...); // call internal at 0xad97f4
    const char* str = "mvpMatrix";
    sub_AD91D0(...); // call internal at 0xad9850
    const char* str = "vSrcUV";
    sub_AD9544(...); // call internal at 0xad9878
    const char* str = "vPosition";
    sub_AD9544(...); // call internal at 0xad98a0
    glDrawElements(...); // call PLT API at 0xad98b4
    sub_AD98FC(...); // call internal at 0xad98c0
    sub_AD98FC(...); // call internal at 0xad98cc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0xad98f8
}
