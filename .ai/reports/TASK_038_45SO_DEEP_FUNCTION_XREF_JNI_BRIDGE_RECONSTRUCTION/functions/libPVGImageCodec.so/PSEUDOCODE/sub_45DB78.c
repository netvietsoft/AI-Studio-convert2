// Function: sub_45DB78
// RVA: 0x45db78, Size: 120 bytes
int64_t sub_45DB78(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x45db8c
    sub_45DBF0(...); // call internal at 0x45dbbc
    pthread_mutex_unlock(...); // call PLT API at 0x45dbe0
    return a0;
}
