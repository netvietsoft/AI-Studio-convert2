// Function: sub_CF5834
// RVA: 0xcf5834, Size: 120 bytes
int64_t sub_CF5834(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xcf5848
    sub_CF58AC(...); // call internal at 0xcf5878
    pthread_mutex_unlock(...); // call PLT API at 0xcf589c
    return a0;
}
