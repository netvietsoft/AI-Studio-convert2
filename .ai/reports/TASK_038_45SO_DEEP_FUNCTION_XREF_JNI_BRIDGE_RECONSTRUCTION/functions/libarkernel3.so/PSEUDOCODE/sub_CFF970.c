// Function: sub_CFF970
// RVA: 0xcff970, Size: 268 bytes
int64_t sub_CFF970(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xcff984
    sub_D00200(...); // call internal at 0xcff9b4
    pthread_mutex_unlock(...); // call PLT API at 0xcff9d8
    return a0;
    sub_CFFA7C(...); // call internal at 0xcffa58
    return a0;
}
