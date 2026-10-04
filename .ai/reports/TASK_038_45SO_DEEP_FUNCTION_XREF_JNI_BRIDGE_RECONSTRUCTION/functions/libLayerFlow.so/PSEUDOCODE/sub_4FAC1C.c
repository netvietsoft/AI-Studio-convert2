// Function: sub_4FAC1C
// RVA: 0x4fac1c, Size: 180 bytes
int64_t sub_4FAC1C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_key_create(...); // call PLT API at 0x4fac3c
    return a0;
    const char* str = "pthread_key_create(&tlsKey, NULL) == 0";
    __strlen_chk(...); // call PLT API at 0x4fac74
    sub_4F964C(...); // call internal at 0x4fac88
    const char* str = "pthread_key_create(&tlsKey, NULL) == 0";
    memcpy(...); // call PLT API at 0x4fac98
    const char* str = "TlsAbstraction";
    sub_4FA660(...); // call internal at 0x4facb0
    __stack_chk_fail(...); // call PLT API at 0x4facb4
    sub_4F968C(...); // call internal at 0x4facc0
    sub_526544(...); // call internal at 0x4facc8
    sub_2BF8C4(...); // call internal at 0x4faccc
}
