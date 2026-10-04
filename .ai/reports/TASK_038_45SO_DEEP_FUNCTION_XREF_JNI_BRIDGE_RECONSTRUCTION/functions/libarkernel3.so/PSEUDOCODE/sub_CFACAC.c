// Function: sub_CFACAC
// RVA: 0xcfacac, Size: 120 bytes
int64_t sub_CFACAC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xcfacc0
    sub_CFAD24(...); // call internal at 0xcfacf0
    pthread_mutex_unlock(...); // call PLT API at 0xcfad14
    return a0;
}
