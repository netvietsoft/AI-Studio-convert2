// Function: sub_1AE240
// RVA: 0x1ae240, Size: 692 bytes
int64_t sub_1AE240(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    malloc(...); // call imported API via PLT at 0x1ae36c
    (*x24)(...); // indirect call at 0x1ae3e0
    (*x28)(...); // indirect call at 0x1ae3f4
    (*x27)(...); // indirect call at 0x1ae404
    (*x27)(...); // indirect call at 0x1ae418
    (*x24)(...); // indirect call at 0x1ae468
    (*x8)(...); // indirect call at 0x1ae480
    (*x8)(...); // indirect call at 0x1ae494
    free(...); // call imported API via PLT at 0x1ae49c
    return a0;
}
