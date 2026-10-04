// Function: sub_429988
// RVA: 0x429988, Size: 120 bytes
int64_t sub_429988(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42999c
    sub_429A00(...); // call internal at 0x4299cc
    pthread_mutex_unlock(...); // call PLT API at 0x4299f0
    return a0;
}
