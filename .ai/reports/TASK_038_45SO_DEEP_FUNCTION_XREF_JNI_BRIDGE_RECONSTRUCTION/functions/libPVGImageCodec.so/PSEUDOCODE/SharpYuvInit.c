// Function: SharpYuvInit
// RVA: 0x49ce64, Size: 196 bytes
int64_t SharpYuvInit(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x49ce7c
    pthread_mutex_unlock(...); // call PLT API at 0x49cee4
    sub_49EE50(...); // call internal at 0x49ceec
    sub_4A0270(...); // call internal at 0x49cef0
    pthread_mutex_unlock(...); // call PLT API at 0x49cf14
    return a0;
}
