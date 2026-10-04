// Function: sub_B19C04
// RVA: 0xb19c04, Size: 88 bytes
int64_t sub_B19C04(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    fileno(...); // call PLT API at 0xb19c20
    __pread_chk(...); // call PLT API at 0xb19c38
    return a0;
}
