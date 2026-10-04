// Function: sub_42F974
// RVA: 0x42f974, Size: 120 bytes
int64_t sub_42F974(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42f988
    sub_42F9EC(...); // call internal at 0x42f9b8
    pthread_mutex_unlock(...); // call PLT API at 0x42f9dc
    return a0;
}
