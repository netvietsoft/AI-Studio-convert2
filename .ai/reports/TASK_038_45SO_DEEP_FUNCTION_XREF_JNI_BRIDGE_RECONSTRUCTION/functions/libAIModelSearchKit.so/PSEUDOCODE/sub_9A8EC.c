// Function: sub_9A8EC
// RVA: 0x9a8ec, Size: 296 bytes
int64_t sub_9A8EC(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    ungetwc(...); // call imported API via PLT at 0x9a928
    (*x8)(...); // indirect call at 0x9a988
    ungetc(...); // call imported API via PLT at 0x9a9d4
    return a0;
}
