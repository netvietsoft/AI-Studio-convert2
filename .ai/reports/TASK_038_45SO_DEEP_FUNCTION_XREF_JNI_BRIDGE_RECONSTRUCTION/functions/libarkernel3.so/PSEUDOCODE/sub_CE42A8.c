// Function: sub_CE42A8
// RVA: 0xce42a8, Size: 232 bytes
int64_t sub_CE42A8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call imported API via PLT at 0xce42e4
    pthread_cond_wait(...); // call imported API via PLT at 0xce430c
    (*x8)(...); // indirect call at 0xce4334
    pthread_mutex_unlock(...); // call imported API via PLT at 0xce436c
    pthread_cond_signal(...); // call imported API via PLT at 0xce4378
    return a0;
}
