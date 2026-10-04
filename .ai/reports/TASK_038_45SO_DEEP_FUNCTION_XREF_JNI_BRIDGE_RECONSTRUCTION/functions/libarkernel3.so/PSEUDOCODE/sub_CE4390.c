// Function: sub_CE4390
// RVA: 0xce4390, Size: 256 bytes
int64_t sub_CE4390(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xce43c4
    pthread_cond_wait(...); // call PLT API at 0xce4400
    pthread_mutex_unlock(...); // call PLT API at 0xce4428
    pthread_cond_signal(...); // call PLT API at 0xce4434
    pthread_mutex_unlock(...); // call PLT API at 0xce4444
    return a0;
    return a0;
}
