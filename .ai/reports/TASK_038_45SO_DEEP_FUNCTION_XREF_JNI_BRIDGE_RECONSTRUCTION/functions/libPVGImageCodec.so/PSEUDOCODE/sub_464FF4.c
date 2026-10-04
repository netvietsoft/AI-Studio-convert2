// Function: sub_464FF4
// RVA: 0x464ff4, Size: 120 bytes
int64_t sub_464FF4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x465008
    sub_46506C(...); // call internal at 0x465038
    pthread_mutex_unlock(...); // call PLT API at 0x46505c
    return a0;
}
