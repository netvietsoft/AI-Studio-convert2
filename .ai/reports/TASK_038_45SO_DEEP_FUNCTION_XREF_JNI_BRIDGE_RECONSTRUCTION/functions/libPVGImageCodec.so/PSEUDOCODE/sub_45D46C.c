// Function: sub_45D46C
// RVA: 0x45d46c, Size: 120 bytes
int64_t sub_45D46C(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x45d480
    sub_45D4E4(...); // call internal at 0x45d4b0
    pthread_mutex_unlock(...); // call PLT API at 0x45d4d4
    return a0;
}
