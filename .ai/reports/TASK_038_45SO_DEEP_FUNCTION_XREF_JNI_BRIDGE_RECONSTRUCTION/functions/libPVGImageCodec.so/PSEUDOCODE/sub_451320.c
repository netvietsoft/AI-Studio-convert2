// Function: sub_451320
// RVA: 0x451320, Size: 120 bytes
int64_t sub_451320(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x451334
    sub_451DA0(...); // call internal at 0x451364
    pthread_mutex_unlock(...); // call PLT API at 0x451388
    return a0;
}
