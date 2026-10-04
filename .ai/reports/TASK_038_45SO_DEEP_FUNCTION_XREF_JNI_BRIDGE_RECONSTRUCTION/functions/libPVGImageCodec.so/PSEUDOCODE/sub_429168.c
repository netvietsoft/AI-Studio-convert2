// Function: sub_429168
// RVA: 0x429168, Size: 120 bytes
int64_t sub_429168(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42917c
    sub_4291E0(...); // call internal at 0x4291ac
    pthread_mutex_unlock(...); // call PLT API at 0x4291d0
    return a0;
}
