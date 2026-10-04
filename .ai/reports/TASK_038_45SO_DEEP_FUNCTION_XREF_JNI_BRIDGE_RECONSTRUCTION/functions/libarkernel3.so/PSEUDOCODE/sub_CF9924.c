// Function: sub_CF9924
// RVA: 0xcf9924, Size: 120 bytes
int64_t sub_CF9924(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xcf9938
    sub_CF999C(...); // call internal at 0xcf9968
    pthread_mutex_unlock(...); // call PLT API at 0xcf998c
    return a0;
}
