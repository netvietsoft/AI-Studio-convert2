// Function: sub_42FEF0
// RVA: 0x42fef0, Size: 120 bytes
int64_t sub_42FEF0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42ff04
    sub_42FF68(...); // call internal at 0x42ff34
    pthread_mutex_unlock(...); // call PLT API at 0x42ff58
    return a0;
}
