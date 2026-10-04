// Function: sub_CEEA00
// RVA: 0xceea00, Size: 120 bytes
int64_t sub_CEEA00(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0xceea14
    sub_CEEA78(...); // call internal at 0xceea44
    pthread_mutex_unlock(...); // call PLT API at 0xceea68
    return a0;
}
