// Function: sub_CED214
// RVA: 0xced214, Size: 120 bytes
int64_t sub_CED214(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xced228
    sub_CED28C(...); // call internal at 0xced258
    pthread_mutex_unlock(...); // call PLT API at 0xced27c
    return a0;
}
