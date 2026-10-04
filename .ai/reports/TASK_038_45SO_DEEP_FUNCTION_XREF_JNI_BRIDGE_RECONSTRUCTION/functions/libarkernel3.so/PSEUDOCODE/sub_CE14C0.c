// Function: sub_CE14C0
// RVA: 0xce14c0, Size: 120 bytes
int64_t sub_CE14C0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xce14d4
    sub_CE3020(...); // call internal at 0xce1504
    pthread_mutex_unlock(...); // call PLT API at 0xce1528
    return a0;
}
