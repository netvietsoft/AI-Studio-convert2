// Function: sub_D000E0
// RVA: 0xd000e0, Size: 120 bytes
int64_t sub_D000E0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xd000f4
    sub_D00158(...); // call internal at 0xd00124
    pthread_mutex_unlock(...); // call PLT API at 0xd00148
    return a0;
}
