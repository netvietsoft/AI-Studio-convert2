// Function: sub_68D440
// RVA: 0x68d440, Size: 164 bytes
int64_t sub_68D440(int64_t a0, int64_t a1, int64_t a2, int64_t a3) {
    const char* str = "%02d";
    __vsprintf_chk(...); // call PLT API at 0x68d4bc
    return a0;
    __stack_chk_fail(...); // call PLT API at 0x68d4e0
}
