// Function: sub_470DE8
// RVA: 0x470de8, Size: 120 bytes
int64_t sub_470DE8(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    pthread_mutex_lock(...); // call PLT API at 0x470dfc
    sub_470E60(...); // call internal at 0x470e2c
    pthread_mutex_unlock(...); // call PLT API at 0x470e50
    return a0;
}
