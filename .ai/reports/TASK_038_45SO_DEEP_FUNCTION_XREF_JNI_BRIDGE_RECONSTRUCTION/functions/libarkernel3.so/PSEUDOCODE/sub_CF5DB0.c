// Function: sub_CF5DB0
// RVA: 0xcf5db0, Size: 120 bytes
int64_t sub_CF5DB0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xcf5dc4
    sub_CF5E28(...); // call internal at 0xcf5df4
    pthread_mutex_unlock(...); // call PLT API at 0xcf5e18
    return a0;
}
