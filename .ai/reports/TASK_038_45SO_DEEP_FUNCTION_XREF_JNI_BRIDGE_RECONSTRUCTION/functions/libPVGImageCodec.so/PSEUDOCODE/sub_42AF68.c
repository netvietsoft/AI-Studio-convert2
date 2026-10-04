// Function: sub_42AF68
// RVA: 0x42af68, Size: 120 bytes
int64_t sub_42AF68(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42af7c
    sub_42AFE0(...); // call internal at 0x42afac
    pthread_mutex_unlock(...); // call PLT API at 0x42afd0
    return a0;
}
