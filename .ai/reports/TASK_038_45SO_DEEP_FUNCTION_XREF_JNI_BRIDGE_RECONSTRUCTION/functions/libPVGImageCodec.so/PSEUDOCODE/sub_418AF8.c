// Function: sub_418AF8
// RVA: 0x418af8, Size: 120 bytes
int64_t sub_418AF8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x418b0c
    sub_41A658(...); // call internal at 0x418b3c
    pthread_mutex_unlock(...); // call PLT API at 0x418b60
    return a0;
}
