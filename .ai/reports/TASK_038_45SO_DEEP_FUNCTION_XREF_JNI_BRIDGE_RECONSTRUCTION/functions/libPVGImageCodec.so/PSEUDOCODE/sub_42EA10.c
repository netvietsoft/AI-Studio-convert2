// Function: sub_42EA10
// RVA: 0x42ea10, Size: 120 bytes
int64_t sub_42EA10(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42ea24
    sub_42EA88(...); // call internal at 0x42ea54
    pthread_mutex_unlock(...); // call PLT API at 0x42ea78
    return a0;
}
