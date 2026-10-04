// Function: sub_B19DF0
// RVA: 0xb19df0, Size: 60 bytes
int64_t sub_B19DF0(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    sem_wait(...); // call imported API via PLT at 0xb19e04
    __errno(...); // call imported API via PLT at 0xb19e10
    return a0;
}
