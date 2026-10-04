// Function: sub_48B22C
// RVA: 0x48b22c, Size: 200 bytes
int64_t sub_48B22C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x48b260
    pthread_cond_wait(...); // call PLT API at 0x48b29c
    pthread_mutex_unlock(...); // call PLT API at 0x48b2c4
    pthread_cond_signal(...); // call PLT API at 0x48b2d0
    pthread_mutex_unlock(...); // call PLT API at 0x48b2e0
    return a0;
}
