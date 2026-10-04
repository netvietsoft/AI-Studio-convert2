// Function: sub_4FAD90
// RVA: 0x4fad90, Size: 180 bytes
int64_t sub_4FAD90(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_setspecific(...); // call PLT API at 0x4fadb0
    return a0;
    const char* str = "pthread_setspecific(tlsKey, pData) == 0";
    __strlen_chk(...); // call PLT API at 0x4fade8
    sub_4F964C(...); // call internal at 0x4fadfc
    const char* str = "pthread_setspecific(tlsKey, pData) == 0";
    memcpy(...); // call PLT API at 0x4fae0c
    const char* str = "SetData";
    sub_4FA660(...); // call internal at 0x4fae24
    __stack_chk_fail(...); // call PLT API at 0x4fae28
    sub_4F968C(...); // call internal at 0x4fae34
    sub_526544(...); // call internal at 0x4fae3c
    sub_2BF8C4(...); // call internal at 0x4fae40
}
