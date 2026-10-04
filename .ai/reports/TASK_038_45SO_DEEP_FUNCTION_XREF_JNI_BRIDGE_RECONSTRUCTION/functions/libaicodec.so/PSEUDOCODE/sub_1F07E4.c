// Function: sub_1F07E4
// RVA: 0x1f07e4, Size: 112 bytes
int64_t sub_1F07E4(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_rwlock_wrlock(...); // call imported API via PLT at 0x1f0800
    (*x19)(...); // indirect call at 0x1f0824
    pthread_rwlock_unlock(...); // call imported API via PLT at 0x1f084c
}
