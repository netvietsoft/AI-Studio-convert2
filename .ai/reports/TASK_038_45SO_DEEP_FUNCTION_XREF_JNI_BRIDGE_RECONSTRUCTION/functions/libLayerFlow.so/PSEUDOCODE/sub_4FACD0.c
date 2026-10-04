// Function: sub_4FACD0
// RVA: 0x4facd0, Size: 192 bytes
int64_t sub_4FACD0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_key_delete(...); // call PLT API at 0x4facf0
    return a0;
    const char* str = "pthread_key_delete(tlsKey) == 0";
    __strlen_chk(...); // call PLT API at 0x4fad28
    sub_4F964C(...); // call internal at 0x4fad3c
    const char* str = "pthread_key_delete(tlsKey) == 0";
    memcpy(...); // call PLT API at 0x4fad4c
    const char* str = "~TlsAbstraction";
    sub_4FA660(...); // call internal at 0x4fad64
    __stack_chk_fail(...); // call PLT API at 0x4fad68
    sub_4F968C(...); // call internal at 0x4fad74
    sub_2BF8C4(...); // call internal at 0x4fad7c
    sub_2BF8C4(...); // call internal at 0x4fad88
    sub_2BF8C4(...); // call internal at 0x4fad8c
}
