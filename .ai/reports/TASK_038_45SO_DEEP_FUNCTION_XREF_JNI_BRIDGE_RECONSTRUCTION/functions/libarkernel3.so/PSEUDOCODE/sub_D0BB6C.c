// Function: sub_D0BB6C
// RVA: 0xd0bb6c, Size: 120 bytes
int64_t sub_D0BB6C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xd0bb80
    sub_D0BBE4(...); // call internal at 0xd0bbb0
    pthread_mutex_unlock(...); // call PLT API at 0xd0bbd4
    return a0;
}
