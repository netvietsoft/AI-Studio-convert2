// Function: sub_42CE18
// RVA: 0x42ce18, Size: 120 bytes
int64_t sub_42CE18(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42ce2c
    sub_42CE90(...); // call internal at 0x42ce5c
    pthread_mutex_unlock(...); // call PLT API at 0x42ce80
    return a0;
}
