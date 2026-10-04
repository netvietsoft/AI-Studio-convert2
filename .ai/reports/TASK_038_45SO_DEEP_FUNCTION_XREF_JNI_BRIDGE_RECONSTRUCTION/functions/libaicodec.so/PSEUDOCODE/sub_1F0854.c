// Function: sub_1F0854
// RVA: 0x1f0854, Size: 256 bytes
int64_t sub_1F0854(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_rwlock_wrlock(...); // call imported API via PLT at 0x1f08a4
    malloc(...); // call imported API via PLT at 0x1f08d4
    memcpy(...); // call imported API via PLT at 0x1f08e4
    free(...); // call imported API via PLT at 0x1f08fc
    pthread_rwlock_unlock(...); // call imported API via PLT at 0x1f0928
    return a0;
}
