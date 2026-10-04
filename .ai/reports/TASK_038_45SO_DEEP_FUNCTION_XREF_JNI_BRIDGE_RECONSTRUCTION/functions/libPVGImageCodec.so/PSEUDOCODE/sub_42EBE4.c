// Function: sub_42EBE4
// RVA: 0x42ebe4, Size: 268 bytes
int64_t sub_42EBE4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x42ebf8
    sub_42F474(...); // call internal at 0x42ec28
    pthread_mutex_unlock(...); // call PLT API at 0x42ec4c
    return a0;
    sub_42ECF0(...); // call internal at 0x42eccc
    return a0;
}
