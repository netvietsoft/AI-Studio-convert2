// Function: sub_42F354
// RVA: 0x42f354, Size: 120 bytes
int64_t sub_42F354(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42f368
    sub_42F3CC(...); // call internal at 0x42f398
    pthread_mutex_unlock(...); // call PLT API at 0x42f3bc
    return a0;
}
